#include "func_server.h"

// associates this type of event with the given function for future execution by
// Func
Status func_server::FuncServiceImpl::hook(ServerContext *context,
                                          const HookRequest *request,
                                          HookReply *reply) {
  LOG(INFO) << "Hook commenced in func_server";
  func_.Hook(request->event_type(), request->event_function());
  return Status::OK;
}

// unregisters an event of the given type, if registered. has no effect if
// already unregistered.
Status func_server::FuncServiceImpl::unhook(ServerContext *context,
                                            const UnhookRequest *request,
                                            UnhookReply *reply) {
  LOG(INFO) << "Unhook commenced in func_server";
  func_.Unhook(request->event_type());
  return Status::OK;
}

// represents an arriving event of the given type with an arbitrary message
// payload
Status func_server::FuncServiceImpl::event(ServerContext *context,
                                           const EventRequest *request,
                                           EventReply *reply) {
  LOG(INFO) << "Event commenced in func_server";
  const auto &optional_any =
      func_.Event(request->event_type(), request->payload());
  if (optional_any) {
    *reply->mutable_payload() = *optional_any;
  } else {
    std::cout << "Event " << request->event_type()
               << " failed to retrieve output.\n";
    return Status(StatusCode::INVALID_ARGUMENT,
                  "Event " + std::to_string(request->event_type()) +
                      " failed to retrieve output.");
  }
  return Status::OK;
}

// represents an event request that reads from a stream
Status func_server::FuncServiceImpl::stream(ServerContext *context, const StreamRequest *request, ServerWriter<EventReply> *writer) {
  LOG(INFO) << "Stream commenced in func_server";
  LOG(INFO) << "Auth context stuff";
  for (auto sref : context->auth_context()->GetPeerIdentity()) {
    LOG(INFO) << "found property :: " << sref.data();
  }
  context->AddInitialMetadata("connected", "yes");
  writer->SendInitialMetadata();
  auto id = std::to_string(reinterpret_cast<uint64_t>(context));
  func_.AddStreamClient(id, request->stream_type(), request->payload());
  // poll for updates
  while (1) {
    auto message = func_.StreamSignal(id);
    if (message) {
      EventReply reply;
      *(reply.mutable_payload()) = *message;
      // relay message to client
      writer->Write(reply);
      // clear signal
      func_.ClearStreamSignal(id);
    }
  }
  // should never reach here, but required for compilation
  return Status::OK;
}

// sets the pre-known map from function names to functions
void func_server::FuncServiceImpl::SetFuncMap(
    const std::unordered_map<
        std::string,
        std::pair<std::function<std::vector<
                      std::tuple<int, std::string, std::string>>(Any)>,
                  std::function<Any(std::vector<std::vector<std::string>>)>>>
        &func_map) {
  LOG(INFO) << "Set func map commenced in func_server";
  func_.SetFuncMap(func_map);
}

void func_server::FuncServiceImpl::SetStreamMap(const stream_mapping &stream_map) {
  func_.SetStreamMap(stream_map);
}

// runs the server on port 50000
void func_server::RunServer(
    const std::unordered_map<
        std::string,
        std::pair<std::function<std::vector<
                      std::tuple<int, std::string, std::string>>(Any)>,
                  std::function<Any(std::vector<std::vector<std::string>>)>>>
        &func_map, const stream_mapping &stream_map) {
  LOG(INFO) << "Run server commenced";
  std::string server_address("0.0.0.0:50000");
  FuncServiceImpl service;
  service.SetFuncMap(func_map);
  service.SetStreamMap(stream_map);
  ServerBuilder builder;
  LOG(INFO) << "Service declared";
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  LOG(INFO) << "Server listening on " << server_address;
  server->Wait();
}

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  LOG(INFO) << "func_server main commenced";
  func_server::RunServer(warble_functions::func_map, warble_functions::stream_map);
  return 0;
}
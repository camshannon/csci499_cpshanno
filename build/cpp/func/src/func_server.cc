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
    LOG(ERROR) << "Event " << request->event_type()
               << " failed to retrieve output.";
    return Status(StatusCode::INVALID_ARGUMENT,
                  "Event " + std::to_string(request->event_type()) +
                      " failed to retrieve output.");
  }
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

// runs the server on port 50000
void func_server::RunServer(
    const std::unordered_map<
        std::string,
        std::pair<std::function<std::vector<
                      std::tuple<int, std::string, std::string>>(Any)>,
                  std::function<Any(std::vector<std::vector<std::string>>)>>>
        &func_map) {
  LOG(INFO) << "Run server commenced";
  std::string server_address("0.0.0.0:50000");
  FuncServiceImpl service;
  service.SetFuncMap(func_map);
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
  func_server::RunServer(warble_functions::func_map);
  return 0;
}
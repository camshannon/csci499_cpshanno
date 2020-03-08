#include "func_server.h"

// associates this type of event with the given function for future execution by
// Func
Status func_server::FuncServiceImpl::hook(ServerContext *context,
                                          const HookRequest *request,
                                          HookReply *reply) {
  func_.Hook(request->event_type(), request->event_function());
  return Status::OK;
}

// unregisters an event of the given type, if registered. has no effect if
// already unregistered.
Status func_server::FuncServiceImpl::unhook(ServerContext *context,
                                            const UnhookRequest *request,
                                            UnhookReply *reply) {
  func_.Unhook(request->event_type());
  return Status::OK;
}

// represents an arriving event of the given type with an arbitrary message
// payload
Status func_server::FuncServiceImpl::event(ServerContext *context,
                                           const EventRequest *request,
                                           EventReply *reply) {
  std::optional<Any> any_from_event =
      func_.Event(request->event_type(), request->payload());
  if (any_from_event) {
    reply->set_allocated_payload(&(*any_from_event));
  } else {
    LOG(ERROR) << "Event: " << request->event_type()
               << " not found in event map.";
    return Status(StatusCode::INVALID_ARGUMENT,
                  "Event: " + std::to_string(request->event_type()) +
                      " not found in event map.");
  }
  return Status::OK;
}

// sets the pre-known map from function names to functions
void func_server::FuncServiceImpl::SetFuncMap(
    const std::unordered_map<std::string, std::function<Any(Any)>> &func_map) {
  func_.SetFuncMap(func_map);
}

// runs the server on port 50000
void func_server::RunServer() {
  LOG(INFO) << "Run server commenced";
  std::string server_address("0.0.0.0:50000");
  FuncServiceImpl service;
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
  LOG(INFO) << "Main commenced";
  func_server::RunServer();
  return 0;
}
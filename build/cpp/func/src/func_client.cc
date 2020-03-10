#include "func_client.h"

// associates this type of event with the given function for future execution by
// Func
void func_client::FuncServiceClient::hook(const int32_t &event_type,
                                          const std::string &event_function) {
  HookRequest request;
  request.set_event_type(event_type);
  request.set_event_function(event_function);
  HookReply reply;
  ClientContext context;
  Status status = stub_->hook(&context, request, &reply);
  if (!status.ok()) {
    LOG(ERROR) << status.error_code() << ": " << status.error_message();
    LOG(ERROR) << "RPC failed";
  }
}

// unregisters an event of the given type, if registered.  has no effect if
// already unregistered
void func_client::FuncServiceClient::unhook(const int32_t &event_type) {
  UnhookRequest request;
  request.set_event_type(event_type);
  UnhookReply reply;
  ClientContext context;
  Status status = stub_->unhook(&context, request, &reply);
  if (!status.ok()) {
    LOG(ERROR) << status.error_code() << ": " << status.error_message();
    LOG(ERROR) << "RPC failed";
  }
}

// represents an arriving event of the given type with an arbitrary message
// payload
std::optional<Any>
func_client::FuncServiceClient::event(const int32_t &event_type, Any &payload) {
  EventRequest request;
  request.set_event_type(event_type);
  *request.mutable_payload() = payload;
  EventReply reply;
  ClientContext context;
  Status status = stub_->event(&context, request, &reply);
  if (!status.ok()) {
    LOG(ERROR) << status.error_code() << ": " << status.error_message();
    LOG(ERROR) << "RPC failed";
    return {};
  }
  return {reply.payload()};
}

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  LOG(INFO) << "Main commenced";
  func_client::FuncServiceClient client(grpc::CreateChannel(
      "localhost:50000", grpc::InsecureChannelCredentials()));
}
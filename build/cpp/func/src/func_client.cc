#include "func_client.h"

// associates this type of event with the given function for future execution by
// Func
void func_client::FuncServiceClient::hook(const int32_t &event_type,
                                          const std::string &event_function) {
  LOG(INFO) << "Hook started in client";
  HookRequest request;
  request.set_event_type(event_type);
  request.set_event_function(event_function);
  HookReply reply;
  ClientContext context;
  Status status = stub_->hook(&context, request, &reply);
  if (!status.ok()) {
    LOG(INFO) << status.error_code() << ": " << status.error_message();
  } else {
    LOG(INFO) << "Successful hook";
  }
}

// unregisters an event of the given type, if registered.  has no effect if
// already unregistered
void func_client::FuncServiceClient::unhook(const int32_t &event_type) {
  LOG(INFO) << "Unhook started in client";
  UnhookRequest request;
  request.set_event_type(event_type);
  UnhookReply reply;
  ClientContext context;
  Status status = stub_->unhook(&context, request, &reply);
  if (!status.ok()) {
    LOG(INFO) << status.error_code() << ": " << status.error_message();
  } else {
    LOG(INFO) << "Successful unhook";
  }
}

// represents an arriving event of the given type with an arbitrary message
// payload
const std::optional<Any>
func_client::FuncServiceClient::event(const int32_t &event_type,
                                      const Any &payload) {
  LOG(INFO) << "Event started in client";
  EventRequest request;
  request.set_event_type(event_type);
  *request.mutable_payload() = payload;
  EventReply reply;
  ClientContext context;
  Status status = stub_->event(&context, request, &reply);
  if (!status.ok()) {
    LOG(INFO) << status.error_code() << ": " << status.error_message();
    return {};
  }
  LOG(INFO) << "Successful event";
  return {reply.payload()};
}
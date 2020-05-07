#include "func_client.h"

// associates this type of event with the given function for future execution by
// Func
void func_client::FuncServiceClient::Hook(const int32_t &event_type,
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
void func_client::FuncServiceClient::Unhook(const int32_t &event_type) {
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
func_client::FuncServiceClient::Event(const int32_t &event_type,
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


const bool func_client::FuncServiceClient::Stream(const std::string &stream_type, const Any &payload, const std::function<void(const std::string &)> &callback) {
  StreamRequest request;
  request.set_stream_type(stream_type);
  *request.mutable_payload() = payload;
  EventReply reply;
  ClientContext context;
  // set the reader of this client instance
  std::unique_ptr<ClientReader<EventReply>> reader(stub_->stream(&context, request));
  reader->WaitForInitialMetadata();
  auto metamap = context.GetServerInitialMetadata();
  std::cout << "server metadata:" << std::endl;
  for (auto itr = metamap.begin(); itr != metamap.end(); ++itr) {
    std::cout << itr->first << " :: " << itr->second << std::endl;
  }
  while (reader->Read(&reply)) {
    std::cout << "got a reply!" << std::endl;
    std::cout << reply.payload().SerializeAsString() << std::endl;
    callback(reply.payload().SerializeAsString());
  }
} 
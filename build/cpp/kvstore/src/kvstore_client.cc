#include "kvstore_client.h"

// puts an element into the key value store
void kvstore_client::KeyValueStoreClient::put(const std::string &key,
                                              const std::string &value) {
  PutRequest request;
  request.set_key(key);
  request.set_value(value);
  PutReply reply;
  ClientContext context;
  Status status = stub_->put(&context, request, &reply);
  if (!status.ok()) {
    LOG(ERROR) << status.error_code() << ": " << status.error_message();
    LOG(ERROR) << "RPC failed";
  } else {
    LOG(INFO) << "Put successful";
  }
}

// gets a value from the key value store
const std::optional<std::vector<std::string>>
kvstore_client::KeyValueStoreClient::get(const std::string &key) {
  ClientContext context;
  auto stream = stub_->get(&context);
  std::vector<std::string> values;
  GetRequest request;
  request.set_key(key);
  stream->Write(request);
  GetReply reply;
  while (stream->Read(&reply)) {
    values.push_back(reply.value());
  }
  stream->WritesDone();
  Status status = stream->Finish();
  if (status.ok()) {
    LOG(INFO) << "Get succesful";
    return {values};
  } else {
    LOG(ERROR) << status.error_code() << ": " << status.error_message();
    LOG(ERROR) << "RPC failed";
    return {};
  }
}

// removes an element from the key value store
void kvstore_client::KeyValueStoreClient::remove(const std::string &key) {
  RemoveRequest request;
  request.set_key(key);
  RemoveReply reply;
  ClientContext context;
  Status status = stub_->remove(&context, request, &reply);
  if (!status.ok()) {
    LOG(ERROR) << status.error_code() << ": " << status.error_message();
    LOG(ERROR) << "RPC failed";
  } else {
    LOG(INFO) << "Remove successful";
  }
}
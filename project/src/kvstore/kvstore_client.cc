#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <grpcpp/grpcpp.h>
#include <glog/logging.h>
#include "kvstore.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using kvstore::PutRequest;
using kvstore::PutReply;
using kvstore::GetRequest;
using kvstore::GetReply;
using kvstore::RemoveRequest;
using kvstore::RemoveReply;
using kvstore::KeyValueStore;

namespace kvstore_client {
//the key value store client
class KeyValueStoreClient {
 public:
  //key value store constructor
 	KeyValueStoreClient(std::shared_ptr<Channel> channel)
 		 : stub_(KeyValueStore::NewStub(channel)) {}

  //put an element into the key value store
  void put(const std::string& key, const std::string& value) {
    PutRequest request;
    request.set_key(key);
    request.set_value(value);
    PutReply reply;
    ClientContext context;
    Status status = stub_->put(&context, request, &reply);
    if(!status.ok()) {
      LOG(ERROR) << status.error_code() << ": " << status.error_message();
      LOG(ERROR) << "RPC failed";
    }
  }

   //gets a value from the key value store
   void get(const std::vector<std::string>& keys) {
   	ClientContext context;
   	auto stream = stub_->get(&context);
   	for(const auto& key : keys) {
   		GetRequest request;
   		request.set_key(key);
   		stream->Write(request);
   		GetReply reply;
   		stream->Read(&reply);
   		LOG(INFO) << key << " : " << reply.value() << "\n";
   	}
   	stream->WritesDone();
   	Status status = stream->Finish();
   	if(!status.ok()) {
   		LOG(ERROR) << status.error_code() << ": " << status.error_message();
   		LOG(ERROR) << "RPC failed";
   	}
   }

   //removes an element from the key value store
   void remove(const std::string& key) {
    RemoveRequest request;
    request.set_key(key);
    RemoveReply reply;
    ClientContext context;
    Status status = stub_->remove(&context, request, &reply);
    if(!status.ok()) {
      LOG(ERROR) << status.error_code() << ": " << status.error_message();
      LOG(ERROR) << "RPC failed";
    }
  }

 private:
 	std::unique_ptr<KeyValueStore::Stub> stub_;
};
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  LOG(INFO) << "Main commenced";
	kvstore_client::KeyValueStoreClient client(grpc::CreateChannel(
    "localhost:50001", grpc::InsecureChannelCredentials()));
  client.put("key1", "value1");
  client.put("key2", "value2");
  client.put("key3", "value3");
  std::vector<std::string> keys = {"key1", "key2", "key3"};
  client.get(keys);
  client.remove("key1");
  client.get(keys);
}
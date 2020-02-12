#include <memory>
#include <string>

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
  void put(const std::string& key, const std::string& value);

  //gets a value from the key value store
  std::vector<std::string> get(const std::vector<std::string>& keys);

  //removes an element from the key value store
  void remove(const std::string& key);

 private:
 	std::unique_ptr<KeyValueStore::Stub> stub_;
};
}
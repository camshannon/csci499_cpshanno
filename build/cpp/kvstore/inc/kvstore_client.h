#include <memory>
#include <string>

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "kvstore.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using kvstore::GetReply;
using kvstore::GetRequest;
using kvstore::KeyValueStore;
using kvstore::PutReply;
using kvstore::PutRequest;
using kvstore::RemoveReply;
using kvstore::RemoveRequest;

namespace kvstore_client {

// the key value store client
class KeyValueStoreClient {
public:
  // key value store client constructor
  KeyValueStoreClient(std::shared_ptr<Channel> channel)
      : stub_(KeyValueStore::NewStub(channel)) {}

  // puts an element into the key value store
  void put(const std::string &key, const std::string &value);

  // gets a value from the key value store
  const std::optional<std::vector<std::string>> get(const std::string &key);

  // removes an element from the key value store
  void remove(const std::string &key);

private:
  // The client object making RPC calls to the kvstore server
  std::unique_ptr<KeyValueStore::Stub> stub_;
};
} // namespace kvstore_client
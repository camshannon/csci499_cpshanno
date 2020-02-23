#include <memory>
#include <string>

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "kvstore.grpc.pb.h"
#include "kvstore.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;
using kvstore::GetReply;
using kvstore::GetRequest;
using kvstore::KeyValueStore;
using kvstore::PutReply;
using kvstore::PutRequest;
using kvstore::RemoveReply;
using kvstore::RemoveRequest;

namespace kvstore_server {

// the key value store server
class KeyValueStoreServiceImpl final : public KeyValueStore::Service {
public:
  // puts a value in the unordered_map
  Status put(ServerContext *context, const PutRequest *request,
             PutReply *reply) override;

  // gets a value from the unordered_map
  Status get(ServerContext *context,
             ServerReaderWriter<GetReply, GetRequest> *stream) override;

  // removes a value from the unordered_map
  Status remove(ServerContext *context, const RemoveRequest *request,
                RemoveReply *reply) override;

private:
  kvstore::KVStore kvstore_;
};

void RunServer();
} // namespace kvstore_server
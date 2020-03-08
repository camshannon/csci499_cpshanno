#include "kvstore_server.h"

// puts a value in the key value store
Status kvstore_server::KeyValueStoreServiceImpl::put(ServerContext *context,
                                                     const PutRequest *request,
                                                     PutReply *reply) {
  kvstore_.Put(request->key(), request->value());
  return Status::OK;
}

// gets a value from the key value store
Status kvstore_server::KeyValueStoreServiceImpl::get(
    ServerContext *context, ServerReaderWriter<GetReply, GetRequest> *stream) {
  GetRequest request;
  while (stream->Read(&request)) {
    GetReply reply;
    std::optional<std::vector<std::string>> values_from_key =
        kvstore_.Get(request.key());
    if (values_from_key) {
      for (int i = 0; i < values_from_key->size(); i++) {
        reply.set_value((*values_from_key)[i]);
        stream->Write(reply);
      }
    } else {
      LOG(ERROR) << "Key: " << request.key()
                 << " not found in key value store.";
      return Status(StatusCode::INVALID_ARGUMENT,
                    "Key: " + request.key() + " not found in key value store.");
    }
  }
  return Status::OK;
}

// removes a value from the key value store
Status kvstore_server::KeyValueStoreServiceImpl::remove(
    ServerContext *context, const RemoveRequest *request, RemoveReply *reply) {
  kvstore_.Remove(request->key());
  return Status::OK;
}

// runs the server on port 50001
void kvstore_server::RunServer() {
  LOG(INFO) << "Run server commenced";
  std::string server_address("0.0.0.0:50001");
  KeyValueStoreServiceImpl service;
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
  kvstore_server::RunServer();
  return 0;
}
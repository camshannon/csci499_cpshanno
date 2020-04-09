#include "kvstore_server.h"

// key value store server constructor
kvstore_server::KeyValueStoreServiceImpl::KeyValueStoreServiceImpl(const String& file) {
  kvstore_ = new kvstore::KVStore(file);
}

kvstore_server::keyValueStoreServiceImpl::~KeyValueStoreServiceImpl() {
  delete kvstore_;
}

// puts a value in the key value store
Status kvstore_server::KeyValueStoreServiceImpl::put(ServerContext *context,
                                                     const PutRequest *request,
                                                     PutReply *reply) {
  LOG(INFO) << "Put for key " << request->key() << " and value "
            << request->value() << " in key value store commenced";
  kvstore_.Put(request->key(), request->value());
  return Status::OK;
}

// gets a value from the key value store
Status kvstore_server::KeyValueStoreServiceImpl::get(
    ServerContext *context, ServerReaderWriter<GetReply, GetRequest> *stream) {
  LOG(INFO) << "Get in key value store commenced";
  GetRequest request;
  GetReply reply;
  stream->Read(&request);
  LOG(INFO) << "Getting value for key " << request.key();
  const auto &values = kvstore_.Get(request.key());
  if (values) {
    LOG(INFO) << "Key " << request.key()
              << " was found. Writing to stream commenced";
    for (unsigned int i = 0; i < values->size(); i++) {
      reply.set_value((*values)[i]);
      stream->Write(reply);
    }
  } else {
    LOG(ERROR) << "Key " << request.key() << " not found in key value store.";
    return Status(StatusCode::INVALID_ARGUMENT,
                  "Key " + request.key() + " not found in key value store.");
  }
  return Status::OK;
}

// removes a value from the key value store
Status kvstore_server::KeyValueStoreServiceImpl::remove(
    ServerContext *context, const RemoveRequest *request, RemoveReply *reply) {
  LOG(INFO) << "Remove in key value store commenced";
  kvstore_.Remove(request->key());
  return Status::OK;
}

// runs the server on port 50001
void kvstore_server::RunServer(const String& store) {
  LOG(INFO) << "Run server commenced";
  std::string server_address("0.0.0.0:50001");
  KeyValueStoreServiceImpl service;
  service.Read(store);
  ServerBuilder builder;
  LOG(INFO) << "Service declared";
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  LOG(INFO) << "Server listening on " << server_address;
  server->Wait();
}
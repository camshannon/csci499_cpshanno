#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <grpcpp/grpcpp.h>
#include <glog/logging.h>
#include "kvstore.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;
using kvstore::PutRequest;
using kvstore::PutReply;
using kvstore::GetRequest;
using kvstore::GetReply;
using kvstore::RemoveRequest;
using kvstore::RemoveReply;
using kvstore::KeyValueStore;

namespace kvstore_server {
//the key value store server
class KeyValueStoreServiceImpl final : public KeyValueStore::Service {
 public:
 	//puts a value in the unordered_map
	Status put(ServerContext* context, const PutRequest* request,
			PutReply* reply) override {
		map[request->key()] = request->value();
		return Status::OK;
	}

	//gets a value from the unordered_map
	Status get(ServerContext* context, 
			ServerReaderWriter<GetReply, GetRequest>* stream) override {
		GetRequest request;
		while(stream->Read(&request)) {
			GetReply reply;
			reply.set_value(map[request.key()]);
			stream->Write(reply);
		}
		return Status::OK;
	}

	//removes a value from the unordered_map
	Status remove(ServerContext* context, const RemoveRequest* request,
			RemoveReply* reply) override {
		map.erase(request->key());
		return Status::OK;
	}

 private:
 	std::unordered_map<std::string, std::string> map;
};

//runs the server on port 50001
void RunServer() {
	LOG(INFO) << "Run server commenced";
	std::string server_address("0.0.0.0:50001");
	KeyValueStoreServiceImpl service;
	ServerBuilder builder;
	LOG(INFO) << "Service declared";
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(&service);
	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << std::endl;

	server->Wait();
}
}

int main(int argc, char** argv) {
	google::InitGoogleLogging(argv[0]);
	LOG(INFO) << "Main commenced";
	kvstore_server::RunServer();
	return 0;
}

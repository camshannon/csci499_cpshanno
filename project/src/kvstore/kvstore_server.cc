#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include <grpcpp/grpcpp.h>

#include <grpc++/grpc++.h>

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

std::unordered_map<bytes, bytes> u_map;

class KVStoreServiceImpl final : public KeyValueStore::Service {
	Status get(ServerContext* context, ServerReaderWriter<GetReply, GetRequest> stream) override {
		GetRequest request;
		while(stream->Read(&request)) {
			GetReply reply;
			reply.set_value(u_map.find(request.key()));
		}

		return Status::OK;
	}

	Status put(ServerContext* context, ServerReaderWriter<PutReply, PutRequest>) override {
		PutRequest request;
		while(stream->Read(&request)) {
			PutReply reply;
			u_map.insert(request.key(), request.value());
		}

		return Status::OK;
	}

	Status remove(ServerContext* context, ServerReaderWriter<RemoveReply, RemoveRequest>) override {
		RemoveRequest request;
		while(stream->Read(&request)) {
			RemoveReply reply;
			u_map.remove(request.key());
		}

		return Status::OK;
	}
}

void RunServer() {
	std::string server_address("0.0.0.0:50001");
	KVStoreServiceImpl service;

	ServerBuilder builder;

	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(&service);
	std::unique_ptr<Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << server_address << std::endl;

	server->Wait();
}

int main(int argc, char** argv) {
	RunServer();

	return 0;
}
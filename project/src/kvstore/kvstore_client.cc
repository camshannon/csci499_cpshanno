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

class KVStoreClient {
 public:
 	KeyValueStoreClient(std::shared_ptr<Channel> channel)
 		: stub_(KeyValueStore::NewStub(channel)) {}

 	void GetValue(const std::vector<bytes>& keys) {
 		ClientContext context;
 		auto stream = stub_->getValue(&context);
 		for(const auto& key : keys) {
 			GetRquest request;
 			request.set_key(key);
 			stream->Write(request);
 			GetReply reply;
 			Stream->Read(&reply);
 			std::cout << key << " : " << reply.value() << "\n";
 		}
 		stream->WritesDone();
 		Status status = stream->Finish();
 		if(!status.ok()) {
 			std::cout << status.error_code() << ": " << status.error_message()
 				<< std::endl;
 			std::cout << "RPC failed";
 		}
 	}

 private:
 	std::unique_ptr<KVStore::Stub> stub_;

};

int main(int argc, char** argv) {
	grpc::ChannelArguements args;
	std::vector<
      std::unique_ptr<grpc::experimental::ClientInterceptorFactoryInterface>>
      interceptor_creators;
  interceptor_creators.push_back(std::unique_ptr<CachingInterceptorFactory>(
      new CachingInterceptorFactory()));
  auto channel = grpc::experimental::CreateCustomChannelWithInterceptors(
      "localhost:50001", grpc::InsecureChannelCredentials(), args,
      std::move(interceptor_creators));
  KVStoreClient client(channel);
  bytes b;
  std::cin << b;
  std::vector<bytes> keys;
  keys.push_back(b);
  client.GetValue(keys);
}
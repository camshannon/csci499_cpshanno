#include <iostream>

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "func_client.h"
#include "func_server.h"
#include "warble_functions.h"
#include "kvstore_server.h"
#include "warble.pb.h"

using google::protobuf::Any;
using warble::FollowReply;
using warble::FollowRequest;
using warble::ProfileReply;
using warble::ProfileRequest;
using warble::ReadReply;
using warble::ReadRequest;
using warble::RegisteruserReply;
using warble::RegisteruserRequest;
using warble::Timestamp;
using warble::Warble;
using warble::WarbleReply;
using warble::WarbleRequest;

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  LOG(INFO) << "Main commenced";
  func_client::FuncServiceClient client(grpc::CreateChannel(
      "localhost:50000", grpc::InsecureChannelCredentials()));
  // ****MAJOR UNSOLVED PROBLEM
  func_server::RunServer(warble_functions::WarbleFunctions::GetFuncMap());
  kvstore_server::RunServer();
  client.hook(0, "Registeruser");
  client.hook(1, "Warble");
  client.hook(2, "Follow");
  client.hook(3, "Read");
  client.hook(4, "Profile");
  if(argc == 3) {
    if(!strcmp(argv[1], "--registeruser")) {
      RegisteruserRequest request;
      Any any;
      request.set_username(argv[2]);
      any.PackFrom(request);
      client.event(0, any);
    }
    else {
      std::cout << "Invalid number of arguments." << std::endl;
    }
  }
  else {
    std::cout << "No arguments found." << std::endl;
  }
}
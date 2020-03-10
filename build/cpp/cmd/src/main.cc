#include <iostream>

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "func_client.h"
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
  client.hook(0, "Registeruser");
  client.hook(1, "Warble");
  client.hook(2, "Follow");
  client.hook(3, "Read");
  client.hook(4, "Profile");
  if(argc == 3) {
    if(!strcmp(argv[1], "--registeruser")) {
      ProfileRequest profile_request;
      request.setPusername(arv[2]);
      Any profile_any;
      profile_any.PackFrom(profile_request);
      if(client.event(4) == std::nullopt) {
        RegisteruserRequest request;
        Any any;
        request.set_username(argv[2]);
        any.PackFrom(request);
        client.event(0, any);
      }
      else {
        std::cout << "Username is taken." << std::endl;
      }
    }
    else {
      std::cout << "Invalid arguments." << std::endl;
    }
  }
  else if(argc == 4) {
    if(!strcmp(argv[3], "--profile") && !strcmp(argv[1], "--user")) {
      ProfileRequest request;
      request.set_username(arv[2]);
      Any any;
      profile_any.PackFrom(profile_request);
      const auto &opt_result = client.event(4);
      if(client.event(4) == std::nullopt) {
        std::cout << "User does not exist." << std::endl;
      }
      else {
        ProfileReply reply;
        opt_result.UnpackTo(&reply);
        std::cout << argv[2] << "'s profile:" << std::endl;
        std::cout << "Followers: ";
        for(int i= 1; i < reply.followers().size(); i++) {
          std::cout << reply.followers()[i];
        }
        std::cout << std::endl;
        std::cout << "Following: ";
        for(int i= 1; i < reply.following().size(), i++) {
          std::cout << following()[i];
        }
      }
    }
    else {
      std::cout << "Invalid arguments." << std::endl;
    }
  }
  else if(argc == 5) {
    if(!strcmp(argv[1], "--user")) {
      //warble request
      if(!strcmp(argv[3], "--warble")) {
        ProfileRequest profile_request;
        request.setPusername(arv[2]);
        Any profile_any;
        profile_any.PackFrom(profile_request);
        if(client.event(4) == std::nullopt) {
        }
      }
      else if(!strcmp(argv[3], "--follow")) {

      }
      else if(!strcmp(argv[3], "--read")) {

      }
    }
    else {
      std::cout << "Invalid arguments." << std::endl;
    }
  }
  else if(argc == 7) {
    if(!strcmp(argv[1], "--user") && !strcmp(argv[3], "--warble") && !strcmp(argv[5], "--reply")) {
      
    }
  }
  else {
    std::cout << "Invalid number of arguments." << std::endl;
  }
}
#include <iostream>
#include <string>

#include <gflags/gflags.h>
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

namespace cmd {
  // the command line tools
class CommandLine {
public:
  // command line tools constructor
  CommandLine();

  // command line tools destructor
  ~CommandLine();

  // hooks the appropriate function ids and functions
  void Hook();

  // check if a user for the username exists
  // @return: true if the user exists, else false
  bool CheckUser(const std::string &username);

  // checks if a warble for the id exists
  // @return: true if warble exists, else false
  bool CheckWarble(const int64_t &id);

  // registers the user with the username
  void RegisterUser(const std::string& username);

  // creates the warble with username, text, and parent_id
  void Warble(const std::string& username, const std::string& text, const int64_t &parent_id);
  
  // follows a user
  void Follow(const std::string& username, const std::string& to_follow);
  
  // recursively reads a thread starting from a warble
  void Read(const int64_t& id);

  // shows a user's followers and following
  void Profile(const std::string& username);
private:
  // helper function to recurse through thread
  void ReadHelper(const int64_t& id, int count);

  //the func client for making calls to server
  func_client::FuncServiceClient *func_client_;
};
} // namespace cmd
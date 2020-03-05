#include <iterator>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "func.grpc.pb.h";

using namespace warble::Timestamp;
using namespace warble::RegisteruserRequest;
using namespace warble::RegisteruserReply;
using namespace warble::WarbleRequest;
using namespace warble::WarbleReply;
using namespace warble::FollowRequest;
using namespace warble::FollowReply;
using namespace warble::ReadRequest;
using namespace warble::ReadReply;
using namespace warble::ProfileRequest;
using namespace warble::Warble;
using google::protobuf::Any;


namespace warble {

// the key value store
class Warble {
public:
  // the warble constructor
  Warble();
  // puts a key value pair into kvstore_map_
  std::vector<std::pair<std::string, std::optional<std::string>>>
  WarbleRequest(const Any& any);

  // 
  const Any& WarbleReply(const Any& any);

  // gets all values for a key from kvstore_map_
  std::optional<std::vector<std::string>> Get(const std::string &key);

  // removes all values with a key from kvstore_map_
  void Remove(const std::string &key);

private:
  // The unordered map for associating function names with functions
  std::unordered_map<std::string, std::pair<std::function<std::vector<std::pair<std::string, std::optional<std::string>>>(Any)>, 
  std::vector<std::pair<std::string, std::optional<std::string>>>(Any)>>> func_map;
  //a coutner for the warble id
  int warble_count;
};
} // namespace kvstore
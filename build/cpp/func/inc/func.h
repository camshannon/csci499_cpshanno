#include <functional>
#include <iterator>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "func.grpc.pb.h"
#include "kvstore_client.h"

using google::protobuf::Any;

namespace func {

// the key value store
class Func {
public:
  // puts a new element into func_map_ or updates the value at event_type
  void Hook(const int32_t &event_type, const std::string &event_function);

  // removes the element with event_type if registered
  void Unhook(const int32_t &event_type);

  // executes the function with the specified event type
  std::optional<Any> Event(const int32_t &event_type, const Any &payload);

  // sets the pre-known map from function names to functions
  void SetFuncMap(
        const   std::unordered_map<
      std::string,
      std::pair<std::function<std::vector<
                    std::tuple<int, std::string, std::string>>(Any)>,
                std::function<Any(std::vector<std::vector<std::string>>)>>> &func_map);

private:
  // the unordered map for storing hooked events
  std::unordered_map<int32_t, std::pair<std::function<std::vector<
                    std::tuple<int, std::string, std::string>>(Any)>,
                std::function<Any(std::vector<std::vector<std::string>>)>>> event_map_;
  // the unordered map for associating function names with functions
  std::unordered_map<
      std::string,
      std::pair<std::function<std::vector<
                    std::tuple<int, std::string, std::string>>(Any)>,
                std::function<Any(std::vector<std::vector<std::string>>)>>> func_map_;
  // the kvstore client for calls to our backend
  kvstore_client::KeyValueStoreClient kvstore_client;
};
} // namespace func
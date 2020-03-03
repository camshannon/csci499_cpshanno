#include <functional>
#include <iterator>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "func.grpc.pb.h"

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
      const std::unordered_map<std::string, std::function<Any(Any)>> &func_map);

private:
  // The unordered map for storing hooked events
  std::unordered_map<int32_t, std::function<Any(Any)>> event_map_;
  // The unordered map for associating function names with functions
  std::unordered_map<std::string, std::function<Any(Any)>> func_map_;
};
} // namespace func
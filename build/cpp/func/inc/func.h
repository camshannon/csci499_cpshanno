#include <functional>
#include <iterator>
#include <memory>
#include <mutex>
#include <optional>
#include <shared_mutex>
#include <string>
#include <unordered_map>

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "func.grpc.pb.h"
#include "func.pb.h"
#include "kvstore.grpc.pb.h"
#include "kvstore.pb.h"
#include "kvstore_client.h"

using google::protobuf::Any;

// reply vector type for value return
using reply_vector = std::vector<std::vector<std::string>>;

// map type for function names to request/reply pairs
using function_mapping = std::unordered_map<
    std::string,
    std::pair<std::function<
                  std::vector<std::tuple<int, std::string, std::string>>(Any)>,
              std::function<Any(std::vector<std::vector<std::string>>)>>>;

// map type for event types to request/reply pairs
using event_mapping = std::unordered_map<
    int32_t,
    std::pair<std::function<
                  std::vector<std::tuple<int, std::string, std::string>>(Any)>,
              std::function<Any(std::vector<std::vector<std::string>>)>>>;

namespace func {

// the func fucntions for hooking, unhook, and executing events
class Func {
public:
  // func constructor
  Func();

  // func destructor
  ~Func();

  // puts a new element into func_map_ or updates the value at event_type
  void Hook(const int32_t &event_type, const std::string &event_function);

  // removes the element with event_type if registered
  void Unhook(const int32_t &event_type);

  // executes the function with the specified event type
  const std::optional<Any> Event(const int32_t &event_type, const Any &payload);

  // sets the pre-known map from function names to functions
  void SetFuncMap(
      const function_mapping
          &func_map);

  // gets the event map
  //  for testing purposes
  event_mapping
  GetEventMap();

  // sets the key value store client for storage
  void SetKVStoreClient();

private:
  // the unordered map for storing hooked events
  event_mapping event_map_;
  // the unordered map for associating function names with functions
  function_mapping func_map_;
  // the kvstore client for calls to our backend
  kvstore_client::KeyValueStoreClient *kvstore_client_;
  // the mutex for obtaining locks on the unordered map
  mutable std::shared_mutex mutex_;
};
} // namespace func
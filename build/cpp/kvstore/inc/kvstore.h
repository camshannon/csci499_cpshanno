#include <fstream>
#include <iterator>
#include <mutex>
#include <optional>
#include <shared_mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "kvstore.pb.h"

using google::protobuf::Any;
using kvstore::KVMap;
using kvstore::KVPair;

namespace kvstore {

// the key value store
class KVStore {
public:
  // key value store constructor
  KVStore(const std::string &store);

  // read key value store to file
  void ReadFile();

  // write key value store to file
  void WriteFile();

  // puts a key value pair into kvstore_map_
  void Put(const std::string &key, const std::string &value);

  // gets all values for a key from kvstore_map_
  const std::optional<std::vector<std::string>> Get(const std::string &key);

  // removes all values with a key from kvstore_map_
  void Remove(const std::string &key);

private:
  // the unordered map for storing the key value pair
  std::unordered_map<std::string, std::vector<std::string>> kvstore_map_;

  // the mutex for obtaining locks on the unordered map
  mutable std::shared_mutex mutex_;

  std::string store_;
};
} // namespace kvstore
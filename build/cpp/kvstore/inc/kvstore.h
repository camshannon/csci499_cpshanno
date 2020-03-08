#include <iterator>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace kvstore {

// the key value store
class KVStore {
public:
  // puts a key value pair into kvstore_map_
  void Put(const std::string &key, const std::string &value);

  // gets all values for a key from kvstore_map_
  std::optional<std::vector<std::string>> Get(const std::string &key);

  // removes all values with a key from kvstore_map_
  void Remove(const std::string &key);

private:
  // The unordered map for storing the key value pair
  std::unordered_map<std::string, std::vector<std::string>> kvstore_map_;
};
} // namespace kvstore
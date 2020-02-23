#include <iterator>
#include <optional>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace kvstore {

// the key value store
class KVStore {
public:
  // puts a key value pair into the unordered map
  void Put(const std::string &key, const std::string &value);

  // gets all values for a key from the unordered map
  std::optional<std::vector<std::string>> Get(const std::string &key);

  // removes all values with a key from the unordered map
  void Remove(const std::string &key);

private:
  // The unordered map for storing the key value pair
  std::unordered_map<std::string, std::vector<std::string>> kvstore_map_;
};
} // namespace kvstore
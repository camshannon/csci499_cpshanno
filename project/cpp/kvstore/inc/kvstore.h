#include <string>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <unordered_map>

namespace kvstore {

//the key value store
class KVStore {
 public:
  //puts a key, value pair into the unordered map
  void put(std::string key, std::string value);

  //gets all values for a key from the unordered map
  std::vector<std::string> get(std::string key);

  //removes all values with a key from the map
  void remove(std::string key);
 private:
  std::unordered_map<std::string, std::vector<std::string>> map_;
};
}
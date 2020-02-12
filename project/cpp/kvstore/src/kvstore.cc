#include "../inc/kvstore.h"

//puts a key, value pair into the unordered map
void kvstore::KVStore::put(std::string key, std::string value) {
  if(map_.find(key) != map_.end()) {
    map_[key].push_back(value);
  }
  else {
    std::vector<std::string> v (1, value);
    map_[key] = v;
  }
}

//gets all values for a key from the unordered map
std::vector<std::string> kvstore::KVStore::get(std::string key) {
  std::unordered_map<std::string, std::vector<std::string>>::iterator it = map_.find(key);
  if(it == map_.end()) {
    throw std::invalid_argument("Key not found in key value store");
  }
  return it->second;
}

//removes all values with a key from the map
void kvstore::KVStore::remove(std::string key) {
  map_.erase(key);
}
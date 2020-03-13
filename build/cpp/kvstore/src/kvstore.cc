#include "kvstore.h"

#include <iostream>

// puts a key value pair into the unordered map
void kvstore::KVStore::Put(const std::string &key, const std::string &value) {
  std::unique_lock lock(mutex_);
  if (kvstore_map_.find(key) != kvstore_map_.end()) {
    kvstore_map_[key].push_back(value);
  } else {
    std::vector<std::string> v(1, value);
    kvstore_map_[key] = v;
  }
}

// gets all values for a key from the unordered map
const std::optional<std::vector<std::string>>
kvstore::KVStore::Get(const std::string &key) {
  std::shared_lock lock(mutex_);
  std::unordered_map<std::string, std::vector<std::string>>::iterator it =
      kvstore_map_.find(key);
  if (it != kvstore_map_.end()) {
    return {it->second};
  }
  return {};
}

// removes all values with a key from the unordered map
void kvstore::KVStore::Remove(const std::string &key) {
  std::unique_lock lock(mutex_);
  kvstore_map_.erase(key);
}
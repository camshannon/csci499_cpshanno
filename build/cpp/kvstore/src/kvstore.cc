#include "kvstore.h"

// key value store constructor
kvstore::KVStore::KVStore(const std::string& store) {
  store_ = "data/" + store;
  ReadFile();
}

// read key value store
void kvstore::KVStore::ReadFile() {
  std::ifstream input_file(store_, std::ifstream::in);
  std::string read = "";
  std::string key = "";
  while(std::getline(input_file, read)) {
    if(read.at(0) == 'k') {
      key = read.substr(1);
    }
    else {
      this->Put(key, read.substr(1));
    }
  }
}

// write key value store
void kvstore::KVStore::WriteFile() {
  std::ofstream output_file(store_, std::ofstream::out | std::ofstream::trunc);
  std::unordered_map<std::string, std::vector<std::string>>::iterator it = kvstore_map_.begin();
    for(std::unordered_map<std::string, std::vector<std::string>>::iterator it = kvstore_map_.begin(); it != kvstore_map_.end(); ++it) {
      output_file << "k" << it->first << "\n";
      for (const auto &value : it->second) {
        output_file << "v" << value << "\n";
      }
    }
}

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
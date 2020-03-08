#include "func.h"

// puts a new element into func_map_ or updates the value at event_type
void func::Func::Hook(const int32_t &event_type,
                      const std::string &event_function) {
  event_map_[event_type] = func_map_[event_function];
}

// removes the element with event_type if registered
void func::Func::Unhook(const int32_t &event_type) {
  event_map_.erase(event_type);
}

// executes the request and reply functions with the specified event type
std::optional<Any> func::Func::Event(const int32_t &event_type,
                                     const Any &payload) {
  const auto &vector_for_storage = (event_map_[event_type].first)(payload);
  std::vector<std::vector<std::string>> vector_output;
  for(auto tuple_for_storage : vector_for_storage) {
    const auto &storage_request_type = std::get<0>(tuple_for_storage);
    const auto &key = std::get<1>(tuple_for_storage);
    const auto &value = std::get<2>(tuple_for_storage);
    std::vector<std::string> value_vector;
    //put request
    if(storage_request_type == 0) {
      kvstore_client.put(key, value);
      value_vector.push_back(value);
    }
    //get request
    else if(storage_request_type == 1) {
      const auto &opt_value_vector = kvstore_client.get(key);
      //if key was found, set value vector to the found value
      if(opt_value_vector) {
        value_vector = *opt_value_vector;
      }
    }
    //remove request
    else if(storage_request_type == 2) {
      kvstore_client.remove(key);
      value_vector.push_back(key);
      vector_output.push_back(value);
    }
    //error request
    else if(storage_request_type == -1) {
      return {};
    }
    vector_output.push_back(value_vector);
  }
  return {(event_map_[event_type].second)(vector_output)};
}

// sets the pre-known map from function names to functions
void func::Func::SetFuncMap(
    const std::unordered_map<std::string, std::pair<std::function<std::vector<std::tuple<int, std::string, std::string>>(Any)>, function<Any(std::vector<std::vector<std::string>>)>>> &func_map_) {
  func_map_ = func_map;
}
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
  const auto &storage_requests = (event_map_[event_type].first)(payload);
  for(const auto &storage_request : storage_requests) {
    const auto &request_type = std::get<0>(storage_request);
    const auto &key = std::get<1>(storage_request);
    const auto &value = std::get<2>(storage_request);
    std::vector<std::string> values;
    //put request
    if(storage_request_type == 0) {
      kvstore_client.put(key, value);
      values.push_back(value);
    }
    //get request
    else if(request_type == 1) {
      const auto &optional_values = kvstore_client.get(key);
      //if key was found, set value vector to the found value
      if(optional_values) {
        value_vector = *opt_value_vector;
      }
    }
    //remove request
    else if(storage_request_type == 2) {
      kvstore_client.remove(key);
      values.push_back(key);
      values.push_back(value);
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
  void SetFuncMap(
        const   std::unordered_map<
      std::string,
      std::pair<std::function<std::vector<
                    std::tuple<int, std::string, std::string>>(Any)>,
                std::function<Any(std::vector<std::vector<std::string>>)>>> &func_map) {
    func_map_ = func_map;
  }
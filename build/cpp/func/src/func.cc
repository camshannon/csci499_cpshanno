#include "func.h"

func::Func::Func() {
  kvstore_client_ = new kvstore_client::KeyValueStoreClient(grpc::CreateChannel(
    "localhost:50001", grpc::InsecureChannelCredentials()));
}

// puts a new element into func_map_ or updates the value at event_type
void func::Func::Hook(const int32_t &event_type,
                      const std::string &event_function) {
  const auto &it = func_map_.find(event_function);
  if (it != func_map_.end()) {
    event_map_[event_type] = it->second;
  }
}

// removes the element with event_type if registered
void func::Func::Unhook(const int32_t &event_type) {
  event_map_.erase(event_type);
}

// executes the request and reply functions with the specified event type
const std::optional<Any> func::Func::Event(const int32_t &event_type,
                                     const Any &payload) {
  const auto &storage_requests = (event_map_[event_type].first)(payload);
  std::vector<std::vector<std::string>> result;
  for(const auto &storage_request : storage_requests) {
    const auto &request_type = std::get<0>(storage_request);
    const auto &key = std::get<1>(storage_request);
    const auto &value = std::get<2>(storage_request);
    std::vector<std::string> values;
    //put request
    if(request_type == 0) {
      kvstore_client_->put(key, value);
      values.push_back(value);
    }
    //get request
    else if(request_type == 1) {
      const auto &optional_values = kvstore_client_->get(key);
      //if key was found, set value vector to the found value
      if(optional_values) {
        values = *optional_values;
      }
    }
    //remove request
    else if(request_type == 2) {
      kvstore_client_->remove(key);
      values.push_back(value);
    }
    //error request
    else if(request_type == -1) {
      return {};
    }
    result.push_back(values);
  }
  return {(event_map_[event_type].second)(result)};
}

// sets the pre-known map from function names to functions
void func::Func::SetFuncMap(
  const std::unordered_map<
    std::string,
    std::pair<std::function<std::vector<
                    std::tuple<int, std::string, std::string>>(Any)>,
                std::function<Any(std::vector<std::vector<std::string>>)>>> &func_map) {
    func_map_ = func_map;
}

  // gets the event map
  //  for testing purposes
  std::unordered_map<int32_t, std::pair<std::function<std::vector<
                    std::tuple<int, std::string, std::string>>(Any)>,
                std::function<Any(std::vector<std::vector<std::string>>)>>> func::Func::GetEventMap() {
  return event_map_;
}
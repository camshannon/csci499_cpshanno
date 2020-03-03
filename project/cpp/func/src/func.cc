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

// executes the function with the specified event type
std::optional<Any> func::Func::Event(const int32_t &event_type,
                                     const Any &payload) {
  std::unordered_map<int32_t, std::function<Any(Any)>>::iterator it =
      event_map_.find(event_type);
  if (it != event_map_.end()) {
    return {(it->second)(payload)};
  }
  return {};
}

// sets the pre-known map from function names to functions
void func::Func::SetFuncMap(
    const std::unordered_map<std::string, std::function<Any(Any)>> &func_map) {
  func_map_ = func_map;
}
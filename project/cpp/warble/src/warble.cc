#include "warble.h"

// the warble constructor
warble::Warble::Warble() {
  func_map.insert()
}

// processes a warble request, assigns an id and timestamp, and 
// returns the id, and serialized warble message 
std::vector<std::pair<std::string, std::optional<std::string>>>
warble::Warble::WarbleRequest(const Any& any) {
  WarbleRequest request;
  any.UnpackTo(&request);
  Warble warble;
  warble.set_username(request.username)
  string username = 1;
  string text = 2;  // The contents of the new warble to be posted.
  bytes parent_id = 3;  // (optional) The ID of the warble this is in response to.

}

const Any& warble::Warble::WarbleReply(const Any& any) {

  }

  // gets all values for a key from kvstore_map_
  std::optional<std::vector<std::string>> Get(const std::string &key);

  // removes all values with a key from kvstore_map_
  void Remove(const std::string &key);

private:
  // The unordered map for associating function names with functions
  std::unordered_map<std::string, std::function<Any(Any)>> func_map;
  int warble_count;
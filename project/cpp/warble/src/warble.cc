#include "warble.h"

// the warble constructor
warble_functions::WarbleFunctions::WarbleFunctions() {
  func_map_.insert("Registeruser", std::make_pair(RegisteruserRequest, RegisteruserReply));
  func_map_.insert("Warble", std::make_pair(WarbleRequest, WarbleReply));
  func_map_.insert("Follow", std::make_pair(FollowRequest, FollowReply));
  func_map_.insert("Read", std::make_pair(ReadRequest, ReadReply));
  func_map_.insert("Profile", std::make_pair(ProfileRequest, ProfileReply));
  warble_count_ = 0;
}

const std::unordered_map<std::string, std::pair<std::function<std::vector<std::tuple<int, std::string, std::string>>(Any)>, function<Any(std::vector<std::vector<std::string>>)>>>& warble::Warble::GetFuncMap() {
  return func_map_;
}

  // receives a register user request as an any and packages it for func
  const std::vector<std::tuple<int, std::string, std::string>>& warble::WarbleFunctions::RegisteruserRequest(const Any& any) {
    RegisteruserRequest request;
    any.unpackTo(&request);
    std::tuple<int, std::string, std::string>> user_for_storage = std::make_tuple(0, request.username(), request.username());
    std::tuple<int, std::string, std::string>> user_following_for_storage = std::make_tuple(0, request.username() + "_following", request.username());
    std::tuple<int, std::string, std::string>> user_followers_for_storage = std::make_tuple(0, request.username() + "_followers", request.username());
    std::vector<std::tuple<int, std::string, std::string>> user_vector;
    user_vector.push_back(user_for_storage);
    user_vector.push_back(user_following_for_storage);
    user_vector.push_back(user_followers_for_storage);
    return user_vector;
  }

  // receives a placeholder 2D vector and returns the register user reply
  const Any& warble_functions::WarbleFunctions::RegisteruserReply(const std::vector<std::vector<std::string>>& registeruser_output) {
    RegisteruserReply reply;
    any.packFrom(reply);
    return any;
  }

// processes a warble request, assigns an id and timestamp, and 
// returns the id, and serialized warble message 
const std::vector<std::tuple<int, std::string, std::string>>&
warble_functions::WarbleFunctions::WarbleRequest(const Any& any) {
  WarbleRequest request;
  any.UnpackTo(&request);
  Warble warble;
  warble.set_username(request.username());
  warble.set_text(request.text());
  warble.set_id(warble_count_);
  warble.set_parent_id(request.parent_id());
  int64_t seconds_since_epoch = std::chrono::duration_cast<std::chrono::seconds>(std::system_clock::now().time_since_epoch()).count();
  int64_t microseconds_since_epoch = std::chrono::duration_cast<std::chrono::microseconds>(std::system_clock::now().time_since_epoch()).count();
  Timestamp timestamp;
  timestamp.set_seconds(seconds_since_epoch);
  timestamp.set_microseconds(microseconds_since_epoch);
  warble.set_timestamp(timestamp);
  String warble_output;
  warble.SerializeToString(&warble_output);
  std::vector<std::tuple<int, std::string, std::string>> warble_vector;
  std::tuple<int, std::string, std::string>> warble_for_storage;
  std::tuple<int, std::string, std::string>> warble_for_storage_at_parent;
  //if parent id is empty, it is a base warble
  //otherwise, add the warble to the parent id
  if(warble.parent_id() == "") {
      warble_for_storage = std::make_tuple(0, "warble_" + std::to_string(warble_count_), warble_output);
  }
  else {
    if(Integer.parseInt(warble.parent_id()) >= warble_count_++) {
      //-1 indicates an error has occurred
      warble_for_storage = std::make_tuple(-1, warble.parent_id(), warble_output);
      warble_vector.push_back(warble_for_storage);
    }
    else {
      warble_for_storage = std::make_tuple(0, warble.id(), warble_output);
      warble_for_storage_at_parent = std::make_tuple(0, warble.parent_id(), warble_output);
      warble_vector.push_back(warble_for_storage);
      warble_vector.push_back(warble_for_storage_at_parent);
    }
  }
  return warble_vector;
}

// receives a warble and packages it in a warble reply for the frontend
const Any& warble_functions::WarbleFunctions::WarbleReply(const std::vector<std::vector<std::string>>& warble_output) {
  Warble warble;
  warble.ParseFromString(warble_output);
  WarbleReply reply;
  reply.set_warble(warble_string[0][0]);
  Any any;
  any.PackFrom(reply);
  return reply;
}

// receives a follow request as an any and packages it for func
const std::vector<std::tuple<int, std::string, std::string>>& warble_functions::WarbleFunc::FollowRequest(const Any& any) {
    FollowRequest request;
    any.unpackTo(&request);
    std::String username_following = request.username() + "_following";
    std::String to_follow_followers = request.to_follow() + "_followers";
    std::tuple<int, std::string, std::string> username_following_for_storage = std::make_tuple(0, username_following, request.to_follow());
    std::tuple<int, std::string, std::string> to_follow_followers_for_storage = std::make_tuple(0, to_follow_followers, request.username());
    std::vector<std::tuple<int, std::string, std::string>> follow_vector;
    user_vector.push_back(username_following_for_storage);
    user_vector.push_back(followers_for_storage);
    return user_vector;
}

// receives a placeholder 2D vector and returns the follow reply
const Any& warble_functions::WarbleFunc::FollowReply(const std::vector<std::vector<std::string>>& follow_output) {
    FollowReply reply;
    Any any;
    any.PackFrom(reply);
    return any;
}

// receives a follow request as an any and packages it for func
const std::vector<std::tuple<int, std::string, std::string>>& warble_functions::WarbleFunc::ReadRequest(const Any& any) {
  ReadRequest request;
  any.unpackTo(&request);
  std::tuple<int, std::string, std::string> warble_id_to_read = std::make_tuple(1, "warble_" + request.warble_id, "");
  std::vector<<std::tuple<int, std::string, std::string>> read_vector;
  read_vector.push_back(warble_id_to_read);
  return read_vector;
}

// receives a vector containing all the warbles in reply to the requested warble
const Any& warble_functions::WarbleFunc::ReadReply(const std::vector<std::vector<std::string>>& read_output) {
  ReadReply reply;
  reply.set_warbles(read_output[0]);
  Any any;
  any.PackFrom(reply);
  return any;
}

// receives a profile request as an any and packages it for func
const std::vector<std::tuple<int, std::string, std::string>>& warble_functions::Warble::ProfileRequest(const Any& any) {
  ProfileRequest request;
  any.unpackTo(&request);
  std::tuple<int, std::string, std::string> user_to_read = std::make_tuple(1, request.username(), "");
  std::tuple<int, std::string, std::string> following_to_read = std::make_tuple(1, request.username() + "_following", "");
  std::tuple<int, std::string, std::string> followers_to_read = std::make_tuple(1, request.username() + "_followers", "");
  std::vector<<std::tuple<int, std::string, std::string>> profile_vector;
  profile_vector.push_back(user_to_read);
  profile_vector.push_back(following_to_read);
  profile_vector.push_back(followers_to_read);
  return profile_vector;
}

// receives a vector containing the two vectors of the user's followers and followings
const Any& warble_functions::WarbleFunc::ProfileReply(const std::vector<std::vector<std::string>>& profile_output) {
  ProfileReply reply;
  if(profile_output.size() == 3) {
    reply.set_followers(profile_output[1]);
    reply.set_following(profile_output[2]);
  }
  Any any;
  any.PackFrom(reply);
  return any;
}
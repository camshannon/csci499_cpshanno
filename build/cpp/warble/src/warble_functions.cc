#include "warble_functions.h"

const std::unordered_map<
    std::string,
    std::pair<std::function<
                  std::vector<std::tuple<int, std::string, std::string>>(Any)>,
              std::function<Any(std::vector<std::vector<std::string>>)>>>
    warble_functions::WarbleFunctions::func_map_{
        {"Registeruser", std::make_pair(RegisteruserRequestPackager,
                                        RegisteruserReplyPackager)},
        {"Warble", std::make_pair(WarbleRequestPackager, WarbleReplyPackager)},
        {"Follow", std::make_pair(FollowRequestPackager, FollowReplyPackager)},
        {"Read", std::make_pair(ReadRequestPackager, ReadReplyPackager)},
        {"Profile",
         std::make_pair(ProfileRequestPackager, ProfileReplyPackager)}};

int warble_functions::WarbleFunctions::warble_count_ = 0;

const std::unordered_map<
    std::string,
    std::pair<std::function<
                  std::vector<std::tuple<int, std::string, std::string>>(Any)>,
              std::function<Any(std::vector<std::vector<std::string>>)>>> &
warble_functions::WarbleFunctions::GetFuncMap() {
  LOG(INFO) << "func_map_ retrieval commenced";
  return func_map_;
}

// receives a register user request as an any and packages it for func
const std::vector<std::tuple<int, std::string, std::string>>
warble_functions::WarbleFunctions::RegisteruserRequestPackager(const Any &any) {
  LOG(INFO) << "RegisteruserRequest packaging commenced";
  RegisteruserRequest request;
  any.UnpackTo(&request);
  const auto &following_put =
      std::make_tuple(0, request.username() + "_following", request.username());
  const auto &followers_put =
      std::make_tuple(0, request.username() + "_followers", request.username());
  std::vector<std::tuple<int, std::string, std::string>> puts{following_put,
                                                              followers_put};
  return puts;
}

// receives a placeholder 2D vector and returns the register user reply
const Any warble_functions::WarbleFunctions::RegisteruserReplyPackager(
    const std::vector<std::vector<std::string>> &result) {
  LOG(INFO) << "RegisteruserReply packaging commenced";
  RegisteruserReply reply;
  Any any;
  any.PackFrom(reply);
  return any;
}

// processes a warble request, assigns an id and timestamp, and
// returns the id, and serialized warble message
const std::vector<std::tuple<int, std::string, std::string>>
warble_functions::WarbleFunctions::WarbleRequestPackager(const Any &any) {
  LOG(INFO) << "WarbleRequest packaging commenced";
  WarbleRequest request;
  // the below line is causing me memory leaks when testing with valgrind
  any.UnpackTo(&request);
  Warble warble;
  warble.set_username(*request.release_username());
  warble.set_text(*request.release_text());
  warble.set_id(std::to_string(warble_count_));
  if (request.parent_id() != "") {
    warble.set_parent_id(*request.release_parent_id());
  }
  const auto &seconds = std::chrono::duration_cast<std::chrono::seconds>(
                            std::chrono::system_clock::now().time_since_epoch())
                            .count();
  const auto &useconds =
      std::chrono::duration_cast<std::chrono::microseconds>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();
  (*warble.mutable_timestamp()).set_seconds(seconds);
  (*warble.mutable_timestamp()).set_useconds(useconds);
  std::string serialized_warble;
  warble.SerializeToString(&serialized_warble);
  std::vector<std::tuple<int, std::string, std::string>> puts;
  // if parent id is empty, it is a base warble
  // otherwise, add the warble to the parent id
  if (warble.parent_id() != "") {
    if (std::stoi(warble.parent_id()) >= warble_count_) {
      LOG(ERROR) << "WarbleRequest packaged with invalid parent_id";
      // -1 indicates an error has occurred
      const auto &warble_put = std::make_tuple(
          -1, "warble_" + std::to_string(warble_count_), serialized_warble);
      puts.push_back(warble_put);
    } else {
      LOG(INFO) << "WarbleRequest packaged with non-empty parent_id";
      const auto &warble_put = std::forward_as_tuple(
          0, "warble_" + std::to_string(warble_count_), serialized_warble);
      const auto &parent_put =
          std::make_tuple(0, "warble_" + warble.parent_id(), serialized_warble);
      puts.push_back(warble_put);
      puts.push_back(parent_put);
      warble_count_++;
    }
  } else {
    LOG(INFO) << "WarbleRequest packaged with empty parent_id";
    const auto &warble_put = std::make_tuple(
        0, "warble_" + std::to_string(warble_count_), serialized_warble);
    puts.push_back(warble_put);
    warble_count_++;
  }
  return puts;
}

// receives a warble and packages it in a warble reply for the frontend
const Any warble_functions::WarbleFunctions::WarbleReplyPackager(
    const std::vector<std::vector<std::string>> &result) {
  LOG(INFO) << "WarbleReply packaging commenced";
  Warble warble;
  warble.ParseFromString(result[0][0]);
  WarbleReply reply;
  *reply.mutable_warble() = warble;
  Any any;
  any.PackFrom(reply);
  return any;
}

// receives a follow request as an any and packages it for func
const std::vector<std::tuple<int, std::string, std::string>>
warble_functions::WarbleFunctions::FollowRequestPackager(const Any &any) {
  LOG(INFO) << "FollowRequest packaging commenced";
  FollowRequest request;
  any.UnpackTo(&request);
  std::tuple<int, std::string, std::string> username_put = std::make_tuple(
      0, request.username() + "_following", request.to_follow());
  std::tuple<int, std::string, std::string> to_follow_put = std::make_tuple(
      0, request.to_follow() + "_followers", request.username());
  std::vector<std::tuple<int, std::string, std::string>> puts{username_put,
                                                              to_follow_put};
  return puts;
}

// receives a placeholder 2D vector and returns the follow reply
const Any warble_functions::WarbleFunctions::FollowReplyPackager(
    const std::vector<std::vector<std::string>> &result) {
  LOG(INFO) << "FollowReply packaging commenced";
  FollowReply reply;
  Any any;
  any.PackFrom(reply);
  return any;
}

// receives a follow request as an any and packages it for func
const std::vector<std::tuple<int, std::string, std::string>>
warble_functions::WarbleFunctions::ReadRequestPackager(const Any &any) {
  LOG(INFO) << "ReadRequest packaging commenced";
  ReadRequest request;
  any.UnpackTo(&request);
  std::tuple<int, std::string, std::string> id_get =
      std::make_tuple(1, "warble_" + request.warble_id(), "");
  std::vector<std::tuple<int, std::string, std::string>> gets{id_get};
  return gets;
}

// receives a vector containing all the warbles in reply to the requested warble
const Any warble_functions::WarbleFunctions::ReadReplyPackager(
    const std::vector<std::vector<std::string>> &result) {
  LOG(INFO) << "ReadReply packaging commenced";
  ReadReply reply;
  std::vector<Warble> parsed_warbles;
  for (const auto &serialized_warble : result[0]) {
    Warble warble;
    warble.ParseFromString(serialized_warble);
    parsed_warbles.push_back(warble);
  }
  *reply.mutable_warbles() = {parsed_warbles.begin(), parsed_warbles.end()};
  Any any;
  any.PackFrom(reply);
  return any;
}

// receives a profile request as an any and packages it for func
const std::vector<std::tuple<int, std::string, std::string>>
warble_functions::WarbleFunctions::ProfileRequestPackager(const Any &any) {
  LOG(INFO) << "ProfileRequest packaging commenced";
  ProfileRequest request;
  any.UnpackTo(&request);
  std::tuple<int, std::string, std::string> following_get =
      std::make_tuple(1, request.username() + "_following", "");
  std::tuple<int, std::string, std::string> followers_get =
      std::make_tuple(1, request.username() + "_followers", "");
  std::vector<std::tuple<int, std::string, std::string>> gets{following_get,
                                                              followers_get};
  return gets;
}

// receives a vector containing the two vectors of the user's followers and
// followings
const Any warble_functions::WarbleFunctions::ProfileReplyPackager(
    const std::vector<std::vector<std::string>> &result) {
  LOG(INFO) << "ProfileReply packaging commenced";
  ProfileReply reply;
  if (result[0].size() > 0 && result[1].size() > 0) {
    *reply.mutable_following() = {result[0].begin(), result[0].end()};
    *reply.mutable_followers() = {result[1].begin(), result[1].end()};
  } else {
    LOG(ERROR) << "Profile not found";
  }
  Any any;
  any.PackFrom(reply);
  return any;
}
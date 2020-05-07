#include "warble_functions.h"

// receives a register user request as an any and packages it for func
const request_vector
warble_functions::RegisteruserRequestPackager(const Any &any) {
  LOG(INFO) << "RegisteruserRequest packaging commenced";
  RegisteruserRequest request;
  any.UnpackTo(&request);
  const auto &following_put =
      std::make_tuple(0, request.username() + "_following", "");
  const auto &followers_put =
      std::make_tuple(0, request.username() + "_followers", "");
  request_vector puts{following_put,
                                                              followers_put};
  return puts;
}

// receives a placeholder 2D vector and returns the register user reply
const Any warble_functions::RegisteruserReplyPackager(
    const reply_vector &result) {
  LOG(INFO) << "RegisteruserReply packaging commenced";
  RegisteruserReply reply;
  Any any;
  any.PackFrom(reply);
  return any;
}

// processes a warble request, assigns an id and timestamp, and
// returns the id, and serialized warble message
const request_vector
warble_functions::WarbleRequestPackager(const Any &any) {
  LOG(INFO) << "WarbleRequest packaging commenced";
  WarbleRequest request;
  // the below line is causing me memory leaks when testing with valgrind
  any.UnpackTo(&request);
  Warble warble;
  warble.set_username(*request.release_username());
  warble.set_text(*request.release_text());
  warble.set_id(*request.release_id());
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
    LOG(INFO) << "WarbleRequest packaged with non-empty parent_id";
    const auto &warble_put =
        std::make_tuple(0, "warble_" + warble.id(), serialized_warble);
    const auto &parent_put =
        std::make_tuple(0, "warble_" + warble.parent_id(), serialized_warble);
    puts.push_back(warble_put);
    puts.push_back(parent_put);
  } else {
    LOG(INFO) << "WarbleRequest packaged with empty parent_id";
    const auto &warble_put =
        std::make_tuple(0, "warble_" + warble.id(), serialized_warble);
    puts.push_back(warble_put);
  }
  // send this warble to all the relevant stream clients
  std::cout << "adding puts" << std::endl;
  puts.push_back(std::make_tuple(3, "Hashtags", serialized_warble));
  return puts;
}



// receives a warble and packages it in a warble reply for the frontend
const Any warble_functions::WarbleReplyPackager(
    const reply_vector &result) {
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
const request_vector
warble_functions::FollowRequestPackager(const Any &any) {
  LOG(INFO) << "FollowRequest packaging commenced";
  FollowRequest request;
  any.UnpackTo(&request);
  std::tuple<int, std::string, std::string> username_put = std::make_tuple(
      0, request.username() + "_following", request.to_follow());
  std::tuple<int, std::string, std::string> to_follow_put = std::make_tuple(
      0, request.to_follow() + "_followers", request.username());
  request_vector puts{username_put,
                                                              to_follow_put};
  return puts;
}

// receives a placeholder 2D vector and returns the follow reply
const Any warble_functions::FollowReplyPackager(
    const reply_vector &result) {
  LOG(INFO) << "FollowReply packaging commenced";
  FollowReply reply;
  Any any;
  any.PackFrom(reply);
  return any;
}

// receives a follow request as an any and packages it for func
const request_vector
warble_functions::ReadRequestPackager(const Any &any) {
  LOG(INFO) << "ReadRequest packaging commenced";
  ReadRequest request;
  any.UnpackTo(&request);
  std::tuple<int, std::string, std::string> id_get =
      std::make_tuple(1, "warble_" + request.warble_id(), "");
  request_vector gets{id_get};
  return gets;
}

// receives a vector containing all the warbles in reply to the requested warble
const Any warble_functions::ReadReplyPackager(
    const reply_vector &result) {
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
const request_vector
warble_functions::ProfileRequestPackager(const Any &any) {
  LOG(INFO) << "ProfileRequest packaging commenced";
  ProfileRequest request;
  any.UnpackTo(&request);
  std::tuple<int, std::string, std::string> following_get =
      std::make_tuple(1, request.username() + "_following", "");
  std::tuple<int, std::string, std::string> followers_get =
      std::make_tuple(1, request.username() + "_followers", "");
  request_vector gets{following_get,
                                                              followers_get};
  return gets;
}

// receives a vector containing the two vectors of the user's followers and
// followings
const Any warble_functions::ProfileReplyPackager(
    const reply_vector &result) {
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

static const std::vector<std::string> FindHashtags(const std::string &text) {
  std::vector<std::string> hashtags;
  std::cout << "in FINDHASHTAGS\n";
  std::cout << text << std::endl;
  for (size_t i = 0; i < text.length(); ++i) {
    if (text[i] == '#') {
      std::cout << "FOUND THE HASHTAG CHARACTER\n";
      std::string hash;
      while (!isspace(text[i]) && i < text.length()) {
        hash += text[i++];
      }
      LOG(INFO) << "Found hashtag :: " << hash;
      hashtags.push_back(hash);
    }
  }
  return hashtags;
}

// returns a list of clients that should be streamed given the streaming payload and current 
// clients associated with the hashtag stream type
const std::vector<std::string> warble_functions::StreamHandler(const std::vector<std::pair<std::string, Any>> &clients, const std::string &warble) {
  LOG(INFO) << "StreamHandler function called for hashtag stream type";
  warble::Warble w;
  w.ParseFromString(warble);
  const std::vector<std::string> hashes = FindHashtags(w.text());
  std::vector<std::string> ret;
  for (auto pair : clients) {
    auto id = pair.first;
    auto args = pair.second;
    warble::StreamRequest req;
    args.UnpackTo(&req);
    if (std::find(hashes.begin(), hashes.end(), req.hashtag()) != hashes.end()) {
      ret.push_back(id);
    }
  }
  return ret;
}
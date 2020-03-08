#include <gtest/gtest.h>

#include "warble.h"

// test register user request
TEST(WarbleFunctions, RegisteruserRequest) {
  warble_fucntions::WarbleFunctions test_warble_functions;
  RegisteruserRequest request;
  Any any;
  request.set_username("username_0");
  any.PackFrom(request);
  const auto &vector_from_request = (test_warble_functions.getFuncMap()["Registeruser"].first)(any);
  const auto &user_tuple_from_request = vector_from_request[0];
  const auto &following_tuple_from_request = vector_from_request[1];
  const auto &followers_tuple_from_request = vector_from_request[2];
  EXPECT_EQ(std::get<0>(user_tuple_from_request), 0);
  EXPECT_EQ(std::get<0>(following_tuple_from_request), 0);
  EXPECT_EQ(std::get<0>(followers_tuple_from_request), 0);
  EXPECT_EQ(std::get<1>(user_tuple_from_request), "username_0");
  EXPECT_EQ(std::get<1>(following_tuple_from_request),  "username_0_following");
  EXPECT_EQ(std::get<1>(followers_tuple_from_request), "username_0_followers");
  EXPECT_EQ(std::get<2>(user_tuple_from_request), "username_0");
  EXPECT_EQ(std::get<2>(following_tuple_from_request), "username_0");
  EXPECT_EQ(std::get<2>(followers_tuple_from_request), "username_0");
}

// test register user reply
TEST(WarbleFunctions, RegisteruserReply) {
  warble_functions::WarbleFunctions test_warble_functions;
  RegisteruserReply reply;
  std::vector<std::vector<std::string>> registeruser_output;
  std::vector<std::string> registeruser_vector;
  registeruser_vector.push_back("username_1");
  registeruser_output.push_back(registeruser_vector);
  const auto &any_from_reply = (test_warble_functions.getFuncMap()["Registeruser"].second)(registeruser_output);
  EXPECT_TRUE(any_from_reply.UnPackTo(&reply));
}

// test 3 cases of warble request
TEST(WarbleFunctions, WarbleRequest) {
  warble_functions::WarbleFunctions test_warble_functions;
  Warble warble;
  Warble parent_warble;
  WarbleRequest request;
  // test first warble request
  request.set_username("username_0");
  request.set_text("Text for user_0");
  request.set_parent_id("");
  any.PackFrom(request);
  const auto &vector_from_request = (test_warble_functions.getFuncMap()["Warble"].first)(any);
  const auto &warble_tuple_from_request = vector_from_request[0];
  warble.ParseFrom(std::get<2>(tuple_from_request));
  EXPECT_EQ(std::get<0>(warble_tuple_from_request), 0);
  EXPECT_EQ(std::get<1>(warble_tuple_from_request), "0");
  EXPECT_EQ(warble.username(), "username_0");
  EXPECT_EQ(warble.text(), "Text for user_0");
  EXPECT_EQ(warble.id(), "0");
  EXPECT_EQ(warble.parent_id(), "");
  // test second warble request with valid parent
  request.set_username("username_1");
  request.set_text("Text for user_1");
  request.set_parent_id("0");
  any.PackFrom(request);
  vector_from_request = (test_warble_functions.getFuncMap()["Warble"].first)(any);
  warble_tuple_from_request = vector_from_request[0];
  const auto &parent_tuple_from_request = vector_from_request[1];
  warble.ParseFrom(std::get<2>(warble_tuple_from_request));
  parent_warble.ParseFrom(std::get<2>(parent_tuple_from_request));
  EXPECT_EQ(std::get<0>(warble_tuple_from_request), 0);
  EXPECT_EQ(std::get<0>(parent_tuple_from_request), 0);
  EXPECT_EQ(std::get<1>(warble_tuple_from_request), "1");
  EXPECT_EQ(std::get<1>(parent_tuple_from_request), "0");
  EXPECT_EQ(warble.username(), "username_1");
  EXPECT_EQ(parent_warble.username(), "username_1");
  EXPECT_EQ(warble.text(), "Text for user_1");
  EXPECT_EQ(parent_warble.text(), "Text for user_1");
  EXPECT_EQ(warble.id(), "1");
  EXPECT_EQ(parent_warble.id(), "1");
  EXPECT_EQ(warble.parent_id(), "0");
  EXPECT_EQ(parent_warble.parent_id(), "0");
  // test third warble request with invalid parent
  request.set_username("username_2");
  request.set_text("Text for user_2");
  request.set_parent_id("");
  any.PackFrom(request);
  vector_from_request = (test_warble_functions.getFuncMap()["Warble"].first)(any);
  tuple_from_request = vector_from_request[0];
  warble.ParseFrom(std::get<2>(tuple_from_request));
  EXPECT_EQ(std::get<0>(warble_tuple_from_request), -1);
  EXPECT_EQ(std::get<1>(tuple_from_request), "0");
  EXPECT_EQ(warble.username(), "username_2");
  EXPECT_EQ(warble.text(), "Text for user_2");
  EXPECT_EQ(warble.id(), "2");
  EXPECT_EQ(warble.parent_id(), "2");
}

// test warble reply
TEST(WarbleFunctions, WarbleReply) {
  warble_functions::WarbleFunctions test_warble_functions;
  WarbleReply reply;
  Warble warble;
  Timestamp timestamp;
  timestamp.set_seconds(1);
  timestamp.set_useconds(2);
  warble.set_username("username_0");
  warble.set_text("Text for user_0");
  warble.set_id("0");
  warble.set_parent_id("5");
  warble.set_timestamp(timestamp);
  std::vector<std::vector<std::string>> warble_output;
  std::vector<std::string> warble_vector;
  std::string warble_string;
  warble.SerializeToString(&warble_string);
  warble_vector.push_back(warble_string);
  warble_output.push_back(warble_vector);
  const auto &any_from_reply = (test_warble_functions.getFuncMap()["Warble"].second)(warble_output);
  any_from_reply.UnPackTo(&reply);
  warble = reply.warble();
  EXPECT_EQ(warble.username(), "username_0");
  EXPECT_EQ(warble.text(), "Text for user_0");
  EXPECT_EQ(warble.id(), "0");
  EXPECT_EQ(warble.parent_id(), "5");
  EXPECT_EQ(warble.timestamp().seconds(), 1);
  EXPECT_EQ(warble.timestamp().useconds(), 2);
}

// test follow request
TEST(WarbleFunctons, FollowRequest) {
  warble_fucntions::WarbleFunctions test_warble_functions;
  FollowRequest request;
  Any any;
  request.set_username("username_0");
  request.set_to_follow("username_1");
  any.PackFrom(request);
  const auto &vector_from_request = (test_warble_functions.getFuncMap()["Follow"].first)(any);
  const auto &following_tuple_from_request = vector_from_request[0];
  const auto &followers_tuple_from_request = vector_from_request[1];
  EXPECT_EQ(std::get<0>(following_tuple_from_request), 0);
  EXPECT_EQ(std::get<0>(followers_tuple_from_request), 0);
  EXPECT_EQ(std::get<1>(following_tuple_from_request), "username_0_following");
  EXPECT_EQ(std::get<1>(followers_tuple_from_request), "username_0_followers");
  EXPECT_EQ(std::get<2>(following_tuple_from_request), "username_1");
  EXPECT_EQ(std::get<2>(followers_tuple_from_request), "username_0");
}

TEST(WarbleFunctions, FollowReply) {
  warble_functions::WarbleFunctions test_warble_functions;
  FollowReply reply;
  std::vector<std::vector<std::string>> registeruser_output;
  std::vector<std::string> following_vector;
  following_vector.push_back("username_1");
  std::vector<std::string> followers_vector;
  followers_vector.push_back("username_0");
  follow_output.push_back(follow_vector);
  const auto &any_from_reply = (test_warble_functions.getFuncMap()["Follow"].second)(follow_output);
  EXPECT_TRUE(any_from_reply.UnPackTo(&reply));
}

TEST(WarbleFunctions, ReadRequest) {
  warble_fucntions::WarbleFunctions test_warble_functions;
  ReadRequest request;
  Any any;
  request.set_id("0");
  any.PackFrom(request);
  const auto &read_vector_from_request = (test_warble_functions.getFuncMap()["Read"].first)(any);
  const auto &read_tuple_from_request = read_vector_from_request[0];
  EXPECT_EQ(std::get<0>(read_tuple_from_request), 1);
  EXPECT_EQ(std::get<1>(read_tuple_from_request), "0");
  EXPECT_EQ(std::get<2>(read_tuple_from_request), "");
}

TEST(WarbleFunctions, ReadReply) {
  warble_functions::WarbleFunctions test_warble_functions;
  ReadReply reply;
  Warble warble;
  Timestamp timestamp;
  std::vector<std::vector<std::string>> read_output;
  std::vector<std::string> read_vector;
  std::string read_string_0;
  std::string read_string_1;
  timestamp.set_seconds(1);
  timestamp.set_useconds(2);
  warble.set_username("username_0");
  warble.set_text("Text for user_0");
  warble.set_id("0");
  warble.set_parent_id("5");
  warble.set_timestamp(timestamp);
  warble.SerializeToString(&read_string_0);
  read_vector.push_back(read_string_0);
  warble.set_username("username_1");
  warble.set_text("Text for user_1");
  warble.set_id("1");
  warble.set_parent_id("6");
  warble.set_timestamp(timestamp);
  warble.SerializeToString(&read_string_1);
  read_vector.push_back(read_string_1);
  warble_output.push_back(read_vector);
  const auto &any_from_reply = (test_warble_functions.getFuncMap()["Read"].second)(read_output);
  any_from_reply.UnPackTo(&reply);
  vector<Warble> warbles = any_from_reply.UnPackTo(&reply);
  EXPECT_EQ(warbles[0].username(), "username_0");
  EXPECT_EQ(warbles[0].text(), "Text for user_0");
  EXPECT_EQ(warbles[0].id(), "0");
  EXPECT_EQ(warbles[0].parent_id(), "5");
  EXPECT_EQ(warbles[0].timestamp().seconds(), 1);
  EXPECT_EQ(warbles[0].timestamp().useconds(), 2);
  EXPECT_EQ(warbles[1].username(), "username_1");
  EXPECT_EQ(warbles[1].text(), "Text for user_1");
  EXPECT_EQ(warbles[1].id(), "1");
  EXPECT_EQ(warbles[1].parent_id(), "6");
  EXPECT_EQ(warbles[1].timestamp().seconds(), 1);
  EXPECT_EQ(warbles[1].timestamp().useconds(), 2);
}

TEST(WarbleFunctions, ProfileRequest) {
  warble_functions::WarbleFunctions test_warble_functions;
  ProfileRequest request;
  Any any;
  request.set_username("username_0");
  any.PackFrom(request);
  const auto &profile_vector_from_request = (test_warble_functions.getFuncMap()["Profile"].first)(any);
  const auto &user_tuple_from_request = profile_vector_from_request[0];
  const auto &following_tuple_from_request = profile_vector_from_request[1];
  const auto &followers_tuple_from_request = profile_vector_from_request[2];
  EXPECT_EQ(std::get<0>(user_tuple_from_request), 0);
  EXPECT_EQ(std::get<0>(following_tuple_from_request), 0);
  EXPECT_EQ(std::get<0>(followers_tuple_from_request), 0);
  EXPECT_EQ(std::get<1>(user_tuple_from_request), "username_0");
  EXPECT_EQ(std::get<1>(followers_tuple_from_request), "username_0_following");
  EXPECT_EQ(std::get<1>(following_tuple_from_request), "username_0_followers");
  EXPECT_EQ(std::get<2>(user_tuple_from_request), "");
  EXPECT_EQ(std::get<2>(following_tuple_from_request), "");
  EXPECT_EQ(std::get<2>(followers_tuple_from_request), "");
}

TEST(WarbleFunctions, ProfileReply) {
  warble_functions::WarbleFunctions test_warble_functions;
  ProfileReply reply;
  std::vector<std::vector<std::string>> proflie_output;
  std::vector<std::string> user_vector;
  std::vector<std::string> followers_vector;
  std::vector<std::string> following_vector;
  const auto &any_from_reply = (test_warble_functions.getFuncMap()["Profile"].second)(profile_output);
  any_from_reply.unPackTo(&reply);
  EXPECT_FALSE(reply.has_followers());
  EPECT_FALSE(reply.has_following());
  user_vector.push_back("username_0");
  followers_vector.push_back("username_1");
  followers_vector.push_back("username_2");
  following_vector.push_back("username_3");
  following_vector.push_back("username_4");
  profile_output.push_back(user_vector);
  profile_output.push_back(following_vector);
  profile_output.push_back(follower_vector);
  any_from_reply = (test_warble_functions.getFuncMap()["Profile"].second)(profile_output);
  any_from_reply.unPackTo(&reply);
  vector<std::string> followers = reply.followers();
  vector<std::string> following = reply.following();
  EXPECT_EQ(followers[0], "username_1");
  EXPECT_EQ(followers[1], "username_2");
  EXPECT_EQ(following[0], "username_3");
  EXPECT_EQ(following[0], "username_4";)
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
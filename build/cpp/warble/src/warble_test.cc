#include <gtest/gtest.h>

#include "warble_functions.h"

// test register user request packager
TEST(WarbleFunctions, RegisteruserRequestPackager) {
  RegisteruserRequest request;
  Any any;
  request.set_username("username_0");
  any.PackFrom(request);
  const auto &puts = (warble_functions::WarbleFunctions::GetFuncMap().at("Registeruser").first)(any);
  const auto &following_put = puts[0];
  const auto &followers_put = puts[1];
  EXPECT_EQ(std::get<0>(following_put), 0);
  EXPECT_EQ(std::get<1>(following_put),  "username_0_following");
  EXPECT_EQ(std::get<2>(following_put), "username_0");
  EXPECT_EQ(std::get<0>(followers_put), 0);
  EXPECT_EQ(std::get<1>(followers_put), "username_0_followers");
  EXPECT_EQ(std::get<2>(followers_put), "username_0");
}

// test register user reply packager
TEST(WarbleFunctions, RegisteruserReplyPackager) {
  std::vector<std::vector<std::string>> result { {"username_0"} };
  RegisteruserReply reply;
  const auto &any = (warble_functions::WarbleFunctions::GetFuncMap().at("Registeruser").second)(result);
  EXPECT_TRUE(any.UnpackTo(&reply));
}

// test warble request packager with no parent
TEST(WarbleFunctions, WarbleRequestPackagerNoParent) {
  WarbleRequest request;
  Warble warble;
  Any any;
  request.set_username("username_0");
  request.set_text("Text for user_0");
  any.PackFrom(request);
  const auto &puts = (warble_functions::WarbleFunctions::GetFuncMap().at("Warble").first)(any);
  const auto &warble_put = puts[0];
  warble.ParseFromString(std::get<2>(warble_put));
  EXPECT_EQ(std::get<0>(warble_put), 0);
  EXPECT_EQ(std::get<1>(warble_put), "warble_0");
  EXPECT_EQ(warble.username(), "username_0");
  EXPECT_EQ(warble.text(), "Text for user_0");
  EXPECT_EQ(warble.id(), "0");
  EXPECT_EQ(warble.parent_id(), "");
  LOG(INFO) << warble.timestamp().seconds();
  LOG(INFO) << warble.timestamp().useconds();
}

// test warble request packager with valid parent
TEST(WarbleFunctions, WarbleRequestPackagerValidParent) {
  WarbleRequest request;
  Warble warble;
  Warble parent_warble;
  Any any;
  request.set_username("username_1");
  request.set_text("Text for user_1");
  request.set_parent_id("0");
  any.PackFrom(request);
  const auto &puts = (warble_functions::WarbleFunctions::GetFuncMap().at("Warble").first)(any);
  const auto &warble_put = puts[0];
  const auto &parent_put = puts[1];
  warble.ParseFromString(std::get<2>(warble_put));
  parent_warble.ParseFromString(std::get<2>(parent_put));
  EXPECT_EQ(std::get<0>(warble_put), 0);
  EXPECT_EQ(std::get<1>(warble_put), "warble_1");
  EXPECT_EQ(warble.username(), "username_1");
  EXPECT_EQ(warble.text(), "Text for user_1");
  EXPECT_EQ(warble.id(), "1");
  EXPECT_EQ(warble.parent_id(), "0");
  LOG(INFO) << warble.timestamp().seconds();
  LOG(INFO) << warble.timestamp().useconds();
  EXPECT_EQ(std::get<0>(parent_put), 0);
  EXPECT_EQ(std::get<1>(parent_put), "warble_0");
  EXPECT_EQ(parent_warble.username(), "username_1");
  EXPECT_EQ(parent_warble.text(), "Text for user_1");
  EXPECT_EQ(parent_warble.id(), "1");
  EXPECT_EQ(parent_warble.parent_id(), "0");
  LOG(INFO) << parent_warble.timestamp().seconds();
  LOG(INFO) << parent_warble.timestamp().useconds();
}

// test warble request packager with invalid parent
TEST(WarbleFunctions, WarbleRequestPackagerInvalidParent) {
  WarbleRequest request;
  Warble warble;
  Any any;
  request.set_username("username_2");
  request.set_text("Text for user_2");
  request.set_parent_id("2");
  any.PackFrom(request);
  const auto &puts = (warble_functions::WarbleFunctions::GetFuncMap().at("Warble").first)(any);
  const auto &warble_put = puts[0];
  warble.ParseFromString(std::get<2>(warble_put));
  EXPECT_EQ(std::get<0>(warble_put), -1);
  EXPECT_EQ(std::get<1>(warble_put), "warble_2");
  EXPECT_EQ(warble.username(), "username_2");
  EXPECT_EQ(warble.text(), "Text for user_2");
  EXPECT_EQ(warble.id(), "2");
  EXPECT_EQ(warble.parent_id(), "2");
  LOG(INFO) << warble.timestamp().seconds();
  LOG(INFO) << warble.timestamp().useconds();
}

// test warble reply packager
TEST(WarbleFunctions, WarbleReplyPackager) {
  WarbleReply reply;
  Warble warble;
  std::string serialized_warble;
  warble.set_username("username_0");
  warble.set_text("Text for user_0");
  warble.set_id("0");
  warble.set_parent_id("5");
  (*warble.mutable_timestamp()).set_seconds(1583746176);
  (*warble.mutable_timestamp()).set_useconds(1583746176242768);
  warble.SerializeToString(&serialized_warble);
  std::vector<std::vector<std::string>> result { {serialized_warble} };
  const auto &any = (warble_functions::WarbleFunctions::GetFuncMap().at("Warble").second)(result);
  any.UnpackTo(&reply);
  warble = reply.warble();
  EXPECT_EQ(warble.username(), "username_0");
  EXPECT_EQ(warble.text(), "Text for user_0");
  EXPECT_EQ(warble.id(), "0");
  EXPECT_EQ(warble.parent_id(), "5");
  EXPECT_EQ(warble.timestamp().seconds(), 1583746176);
  EXPECT_EQ(warble.timestamp().useconds(), 1583746176242768);
}

// test follow request packager
//  profile request will ensure to_follow exists
TEST(WarbleFunctons, FollowRequestPackager) {
  FollowRequest request;
  Any any;
  request.set_username("username_0");
  request.set_to_follow("username_1");
  any.PackFrom(request);
  const auto &puts = (warble_functions::WarbleFunctions::GetFuncMap().at("Follow").first)(any);
  const auto &username_put = puts[0];
  const auto &to_follow_put = puts[1];
  EXPECT_EQ(std::get<0>(username_put), 0);
  EXPECT_EQ(std::get<1>(username_put), "username_0_following");
  EXPECT_EQ(std::get<2>(username_put), "username_1");
  EXPECT_EQ(std::get<0>(to_follow_put), 0);
  EXPECT_EQ(std::get<1>(to_follow_put), "username_1_followers");
  EXPECT_EQ(std::get<2>(to_follow_put), "username_0");
}

// test follow reply packager
TEST(WarbleFunctions, FollowReplyPackager) {
  FollowReply reply;
  std::vector<std::vector<std::string>> result { {"username_1"}
                                               , {"username_0"} };
  const auto &any = (warble_functions::WarbleFunctions::GetFuncMap().at("Follow").second)(result);
  EXPECT_TRUE(any.UnpackTo(&reply));
}

// test read request packager
TEST(WarbleFunctions, ReadRequestPackager) {
  ReadRequest request;
  Any any;
  request.set_warble_id("0");
  any.PackFrom(request);
  const auto &read_vector_from_request = (warble_functions::WarbleFunctions::GetFuncMap().at("Read").first)(any);
  const auto &read_tuple_from_request = read_vector_from_request[0];
  EXPECT_EQ(std::get<0>(read_tuple_from_request), 1);
  EXPECT_EQ(std::get<1>(read_tuple_from_request), "warble_0");
  EXPECT_EQ(std::get<2>(read_tuple_from_request), "");
}

// test read reply packager
TEST(WarbleFunctions, ReadReplyPackager) {
  ReadReply reply;
  Warble warble;
  std::string serialized_warble;
  warble.set_username("username_1");
  warble.set_text("Text for user_1");
  warble.set_id("1");
  warble.set_parent_id("0");
  (*warble.mutable_timestamp()).set_seconds(1583746176);
  (*warble.mutable_timestamp()).set_useconds(1583746176242768);
  warble.SerializeToString(&serialized_warble);
  std::vector<std::vector<std::string>> result { {serialized_warble} };
  const auto &any = (warble_functions::WarbleFunctions::GetFuncMap().at("Read").second)(result);
  any.UnpackTo(&reply);
  const auto &warbles = reply.warbles();
  EXPECT_EQ(warbles[0].username(), "username_1");
  EXPECT_EQ(warbles[0].text(), "Text for user_1");
  EXPECT_EQ(warbles[0].id(), "1");
  EXPECT_EQ(warbles[0].parent_id(), "0");
  EXPECT_EQ(warbles[0].timestamp().seconds(), 1583746176);
  EXPECT_EQ(warbles[0].timestamp().useconds(), 1583746176242768);
}

// test profile request
TEST(WarbleFunctions, ProfileRequest) {
  ProfileRequest request;
  Any any;
  request.set_username("username_0");
  any.PackFrom(request);
  const auto &gets = (warble_functions::WarbleFunctions::GetFuncMap().at("Profile").first)(any);
  const auto &following_get = gets[0];
  const auto &followers_get = gets[1];
  EXPECT_EQ(std::get<0>(following_get), 1);
  EXPECT_EQ(std::get<1>(following_get), "username_0_following");
  EXPECT_EQ(std::get<2>(following_get), "");
  EXPECT_EQ(std::get<0>(followers_get), 1);
  EXPECT_EQ(std::get<1>(followers_get), "username_0_followers");
  EXPECT_EQ(std::get<2>(followers_get), "");
}


TEST(WarbleFunctions, ProfileReply) {
  ProfileReply reply;
  std::vector<std::vector<std::string>> result { {"username_1", "username_2"}
                                               , {"username_3", "username_4"} };
  const auto &any = (warble_functions::WarbleFunctions::GetFuncMap().at("Profile").second)(result);
  any.UnpackTo(&reply);
  const auto &followers = reply.followers();
  const auto &following = reply.following();
  EXPECT_EQ(following[0], "username_1");
  EXPECT_EQ(following[1], "username_2");
  EXPECT_EQ(followers[0], "username_3");
  EXPECT_EQ(followers[1], "username_4");
}


int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
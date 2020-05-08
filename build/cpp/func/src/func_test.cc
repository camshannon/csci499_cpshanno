#include <gtest/gtest.h>

#include "func.h"
#include "warble_functions.h"

// test hook and unhook
//  uses register user request for testing
TEST(Func, HookandUnhook) {
  func::Func func;
  func.SetFuncMap(warble_functions::func_map);
  func.Hook(0, "Registeruser");
  RegisteruserRequest request;
  Any any;
  request.set_username("username_0");
  any.PackFrom(request);
  EXPECT_EQ(std::get<1>((func.GetEventMap().at(0).first)(any)[0]),
            std::get<1>(warble_functions::RegisteruserRequestPackager(any)[0]));
  func.Unhook(0);
  const auto &it = func.GetEventMap().find(0);
  EXPECT_EQ(it, func.GetEventMap().end());
}

// test put event
//  uses register user event for testing
TEST(Func, PutEvent) {
  func::Func func;
  func.SetFuncMap(warble_functions::func_map);
  func.Hook(0, "Registeruser");
  RegisteruserRequest request;
  RegisteruserReply reply;
  Any any;
  request.set_username("username_0");
  any.PackFrom(request);
  const auto &optional_any = func.Event(0, any);
  EXPECT_TRUE(optional_any->UnpackTo(&reply));
}

// test get event
//  uses profile request for testing
TEST(Func, GetEvent) {
  func::Func func;
  func.SetFuncMap(warble_functions::func_map);
  func.Hook(0, "Profile");
  ProfileRequest request;
  ProfileReply reply;
  Any any;
  request.set_username("username_0");
  any.PackFrom(request);
  const auto &optional_any = func.Event(0, any);
  optional_any->UnpackTo(&reply);
  EXPECT_EQ(reply.following()[0], "");
  EXPECT_EQ(reply.followers()[0], "");
}

// tests stream signal related methods
// adds, modifies, and removes a message to a specific client
TEST(Func, StreamSignal) {
  func::Func func;
  // clear incase a fresh db was not used
  func.ClearStreamSignal("1");
  warble::StreamRequest request;
  request.set_hashtag("message");
  auto res = func.StreamSignal("1");
  EXPECT_TRUE(res == std::nullopt);
  func.SetStreamSignal("1", request.SerializeAsString());
  res = func.StreamSignal("1");
  EXPECT_FALSE(res == std::nullopt);
  if (res) {
    res->UnpackTo(&request);
    EXPECT_EQ(request.hashtag(), "message");
  }
  func.ClearStreamSignal("1");
  EXPECT_TRUE(func.StreamSignal("1") == std::nullopt);
  request.set_hashtag("different");
  func.SetStreamSignal("1", request.SerializeAsString());
  res = func.StreamSignal("1");
  EXPECT_FALSE(res == std::nullopt);
  if (res) {
    res->UnpackTo(&request);
    EXPECT_EQ(request.hashtag(), "different");
  }
}

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
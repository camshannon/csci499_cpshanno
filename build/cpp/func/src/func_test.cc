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
TEST(Func, PutEvent1) {
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
  EXPECT_EQ(reply.following()[0], "username_0");
  EXPECT_EQ(reply.followers()[0], "username_0");
}

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
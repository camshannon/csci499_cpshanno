#include <gtest/gtest.h>

#include "func.h"
#include "warble.h"

using warble::Timestamp;

TEST(Func, Hook) {

}

TEST(Func, SetFuncMap) {
  Timestamp timestamp;
  timestamp.set_seconds(0);
  timestamp.set_useconds(1);
  Any any;
  any.packFrom(timestamp);
  std::unordered_map<string event_function, func::FuncPointer> func_map;
  func::Func func;
  func.SetFuncMap(func_map);
  EXPECT_EQ(func.Event(0, any), std::nullopt);
}

TEST(Func, HookandUnHook) {
  Timestamp timestamp;
  timestamp.set_seconds(0);
  timestamp.set_useconds(1);
  Any any;
  any.packFrom(timestamp);
  std::unordered_map<string event_function, func::FuncPointer> func_map;
  func_map["Foo"] = Foo;
  func::Func func;
  func.SetFuncMap(func_map);
  func.Hook(1, "Foo");
  EXPECT_EQ(*(func.Event(1, any)), any);
  func.Unhook(1);
  EXPECT_EQ(func.Event(1), std::nullopt);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
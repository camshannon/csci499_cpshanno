#include <glog/logging.h>
#include <gtest/gtest.h>

#include "kvstore.h"

// test get with an unstored element
TEST(KVStore, GetElementNotFound) {
  kvstore::KVStore kvstore;
  EXPECT_EQ(kvstore.Get("key1"), std::nullopt);
}

// test put with multiple puts
TEST(KVStore, PuttingMultiple) {
  kvstore::KVStore kvstore;
  kvstore.Put("key1", "value1");
  kvstore.Put("key1", "value2");
  kvstore.Put("key1", "value3");
  EXPECT_EQ((*kvstore.Get("key1"))[0], "value1");
  EXPECT_EQ((*kvstore.Get("key1"))[1], "value2");
  EXPECT_EQ((*kvstore.Get("key1"))[2], "value3");
}

// test put then remove
TEST(KVStore, PutAndRemove) {
  kvstore::KVStore kvstore;
  kvstore.Put("key1", "value1");
  EXPECT_EQ((*kvstore.Get("key1"))[0], "value1");
  kvstore.Remove("key1");
  EXPECT_EQ(kvstore.Get("key1"), std::nullopt);
}

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
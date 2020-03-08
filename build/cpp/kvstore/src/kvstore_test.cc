#include <gtest/gtest.h>

#include "kvstore.h"

TEST(KVStore, ElementNotFound) {
  kvstore::KVStore kvstore;
  EXPECT_EQ(kvstore.Get("key1"), std::nullopt);
}

TEST(KVStore, PuttingMultiple) {
  kvstore::KVStore kvstore;
  kvstore.Put("key1", "value1");
  kvstore.Put("key1", "value2");
  kvstore.Put("key1", "value3");
  EXPECT_EQ((*kvstore.Get("key1"))[0], "value1");
  EXPECT_EQ((*kvstore.Get("key1"))[1], "value2");
  EXPECT_EQ((*kvstore.Get("key1"))[2], "value3");
}

TEST(KVStore, PutAndRemove) {
  kvstore::KVStore kvstore;
  kvstore.Put("key1", "value1");
  EXPECT_EQ((*kvstore.Get("key1"))[0], "value1");
  kvstore.Remove("key1");
  EXPECT_EQ(kvstore.Get("key1"), std::nullopt);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
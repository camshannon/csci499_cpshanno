#include <gtest/gtest.h>

#include "../inc/kvstore.h"

TEST(KVStore, ElementNotFound) {
  kvstore::KVStore kvstore;
  EXPECT_THROW(kvstore.get("key1"), std::invalid_argument);
}

TEST(KVStore, PuttingMultiple) {
  kvstore::KVStore kvstore;
  kvstore.put("key1", "value1");
  kvstore.put("key1", "value2");
  kvstore.put("key1", "value3");
  EXPECT_EQ(kvstore.get("key1")[0], "value1");
  EXPECT_EQ(kvstore.get("key1")[1], "value2");
  EXPECT_EQ(kvstore.get("key1")[2], "value3");
}

TEST(KVStore, PutAndRemove) {
  kvstore::KVStore kvstore;
  kvstore.put("key1", "value1");
  EXPECT_EQ(kvstore.get("key1")[0], "value1");
  kvstore.remove("key1");
  EXPECT_THROW(kvstore.get("key1"), std::invalid_argument);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#include <gtest/gtest.h>

#include "kvstore.h"
#include <stdio.h>

// get with an unstored element
TEST(KVStore, GetElementNotFound) {
  kvstore::KVStore kvstore;
  EXPECT_EQ(kvstore.Get("key1"), std::nullopt);
}

// put with multiple puts
TEST(KVStore, PuttingMultiple) {
  kvstore::KVStore kvstore;
  kvstore.Put("key1", "value1");
  kvstore.Put("key1", "value2");
  kvstore.Put("key1", "value3");
  EXPECT_EQ((*kvstore.Get("key1"))[0], "value1");
  EXPECT_EQ((*kvstore.Get("key1"))[1], "value2");
  EXPECT_EQ((*kvstore.Get("key1"))[2], "value3");
}

// put then remove
TEST(KVStore, PutAndRemove) {
  kvstore::KVStore kvstore;
  kvstore.Put("key1", "value1");
  EXPECT_EQ((*kvstore.Get("key1"))[0], "value1");
  kvstore.Remove("key1");
  EXPECT_EQ(kvstore.Get("key1"), std::nullopt);
}

// read & write on existent .txt file
TEST(KVStore, ExistingWriteFile) {
  std::ofstream create_file("data/test1.txt");
  kvstore::KVStore write_kvstore;
  kvstore::KVStore read_kvstore;
  write_kvstore.Put("key1", "value1");
  write_kvstore.Put("key1", "value2");
  write_kvstore.Put("key2", "value3");
  write_kvstore.WriteFile("data/test1.txt");
  read_kvstore.ReadFile("data/test1.txt");
  EXPECT_EQ((*write_kvstore.Get("key1"))[0], (*read_kvstore.Get("key1"))[0]);
  EXPECT_EQ((*write_kvstore.Get("key1"))[1], (*read_kvstore.Get("key1"))[1]);
  EXPECT_EQ((*write_kvstore.Get("key2"))[0], (*read_kvstore.Get("key2"))[0]);
}

// read & write on non-existent .txt file
TEST(KVStore, WriteFileNonExistent) {
  remove("data/test1.txt");
  kvstore::KVStore write_kvstore;
  kvstore::KVStore read_kvstore;
  write_kvstore.Put("key1", "value1");
  write_kvstore.Put("key1", "value2");
  write_kvstore.Put("key2", "value3");
  write_kvstore.WriteFile("data/test1.txt");
  read_kvstore.ReadFile("data/test1.txt");
  EXPECT_EQ((*write_kvstore.Get("key1"))[0], (*read_kvstore.Get("key1"))[0]);
  EXPECT_EQ((*write_kvstore.Get("key1"))[1], (*read_kvstore.Get("key1"))[1]);
  EXPECT_EQ((*write_kvstore.Get("key2"))[0], (*read_kvstore.Get("key2"))[0]);
}

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
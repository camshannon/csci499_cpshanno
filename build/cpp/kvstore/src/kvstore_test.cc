#include <gtest/gtest.h>

#include "kvstore.h"

// get with an unstored element
TEST(KVStore, GetElementNotFound) {
  kvstore::KVStore kvstore("");
  EXPECT_EQ(kvstore.Get("key1"), std::nullopt);
}

// put with multiple puts
TEST(KVStore, PuttingMultiple) {
  kvstore::KVStore kvstore("");
  kvstore.Put("key1", "value1");
  kvstore.Put("key1", "value2");
  kvstore.Put("key1", "value3");
  EXPECT_EQ((*kvstore.Get("key1"))[0], "value1");
  EXPECT_EQ((*kvstore.Get("key1"))[1], "value2");
  EXPECT_EQ((*kvstore.Get("key1"))[2], "value3");
}

// put then remove
TEST(KVStore, PutAndRemove) {
  kvstore::KVStore kvstore("");
  kvstore.Put("key1", "value1");
  EXPECT_EQ((*kvstore.Get("key1"))[0], "value1");
  kvstore.Remove("key1");
  EXPECT_EQ(kvstore.Get("key1"), std::nullopt);
}

// write file on existing file
TEST(KVStore, ExistingWriteFile) {
  kvstore::KVStore kvstore("test1.txt");
  kvstore.Put("key1", "value1");
  kvstore.Put("key1", "value2");
  kvstore.Put("key2", "value3");
  kvstore.WriteFile();
  kvstore.WriteFile();
  }

// write file on non-existent file
TEST(KVStore, WriteFileNonExistent) {
  kvstore::KVStore kvstore("test2.txt");
  kvstore.Put("key1", "value1");
  kvstore.Put("key1", "value2");
  kvstore.Put("key2", "value3");
  kvstore.WriteFile();
}

// write file on unknown file format
TEST(KVStore, WriteFileUnknownFileFormat) {
  kvstore::KVStore kvstore("test3.test3");
  kvstore.Put("key1", "value1");
  kvstore.Put("key1", "value2");
  kvstore.Put("key2", "value3");
  kvstore.WriteFile();
}

// read file on existing file
TEST(KVStore, ReadFileExistent) {
  kvstore::KVStore kvstore("test1.txt");
  kvstore.ReadFile();
  EXPECT_EQ((*kvstore.Get("key1"))[0], "value1");
  EXPECT_EQ((*kvstore.Get("key1"))[1], "value2");
  EXPECT_EQ((*kvstore.Get("key2"))[0], "value3");
}

// read file on non-existent file
TEST(KVSTORE, ReadFileNonExistent) {
  kvstore::KVStore kvstore("test4.txt");
  kvstore.ReadFile();
  EXPECT_EQ(kvstore.Get("key1"), std::nullopt);
}

// read file on unknown file format
TEST(KVStore, ReadFileUnknownFileFormat) {
  kvstore::KVStore kvstore("test3.test3");
  kvstore.ReadFile();
  EXPECT_EQ((*kvstore.Get("key1"))[0], "value1");
  EXPECT_EQ((*kvstore.Get("key1"))[1], "value2");
  EXPECT_EQ((*kvstore.Get("key2"))[0], "value3");
}

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
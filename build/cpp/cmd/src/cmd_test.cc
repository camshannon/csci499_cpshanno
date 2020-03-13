#include <gtest/gtest.h>

#include "cmd.h"

TEST(CommandLine, Hook) {
  func_client::FuncServiceClient client(grpc::CreateChannel(
      "localhost:50000", grpc::InsecureChannelCredentials()));
  cmd::CommandLine command_line(client);
  command_line.hook();
}

TEST(CommandLine, CheckUser) {
  func_client::FuncServiceClient client(grpc::CreateChannel(
      "localhost:50000", grpc::InsecureChannelCredentials()));
  cmd::CommandLine command_line(client);
  EXPECT_FALSE(command_line.CheckUser("username_0"));
}

TEST(CommandLine, CheckWarble) {
  func_client::FuncServiceClient client(grpc::CreateChannel(
      "localhost:50000", grpc::InsecureChannelCredentials()));
  cmd::CommandLine command_line(client);
  EXPECT_FALSE(command_line.CheckWarble(0));
}

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
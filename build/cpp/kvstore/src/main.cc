#include "kvstore_server.h"

DEFINE_bool(store, "", "Stores and loads kvstore form .txt files.");

int main(int argc, char **argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  kvstore_server::RunServer(store);
  return 0;
}
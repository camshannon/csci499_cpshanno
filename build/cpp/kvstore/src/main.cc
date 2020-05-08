#include "kvstore_server.h"

DEFINE_string(store, "", "Stores and loads kvstore form .txt files");

kvstore_server::KeyValueStoreServiceImpl *service;

// calls service destructor upon shutdown signal
void SignalHandler(int signum) {
  LOG(INFO) << "Handling signal: " << signum;
  delete service;
  exit(signum);
}

// function for termination signals
void sig() {
  signal(SIGINT, SignalHandler);
  signal(SIGTERM, SignalHandler);
}

int main(int argc, char **argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  service = new kvstore_server::KeyValueStoreServiceImpl(FLAGS_store);
  std::thread s(sig);  // creates thread catching signals
  kvstore_server::RunServer(service);
  LOG(INFO) << "Main completed";
  return 0;
}
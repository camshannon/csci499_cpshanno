#include "cmd.h"

DEFINE_bool(hook, false, "Hooks warble functions to appropriate ids.");
DEFINE_string(registeruser, "", "Registers the given username.");
DEFINE_string(user, "", "Logs in as the given username.");
DEFINE_string(warble, "", "Creates a new warble with the given text.");
DEFINE_int64(reply, -1,
             "Indicates that the new warble is a reply to the given id.");
DEFINE_string(follow, "", "Starts following the given username.");
DEFINE_int64(read, -1, "Reads the warble thread starting at the given id.");
DEFINE_bool(profile, false,
            "Gets the user's profile of following and followers.");
DEFINE_string(stream, "",
              "Streams all new warbles containing the given hashtag.");

cmd::CommandLine* command_line;
void SignalHandler(int signum) {
  LOG(INFO) << "Handling signal: " << signum;
  delete command_line;
  std::cout << "Leaving Warble ... goodbye!" << std::endl;
  exit(signum);
}

void sig() {
  signal(SIGINT, SignalHandler);
  signal(SIGTERM, SignalHandler);
}

int main(int argc, char** argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  command_line = new cmd::CommandLine();
  std::thread s(sig);  // catches disconnect signal
  // Hook
  if (FLAGS_hook && FLAGS_registeruser == "" && FLAGS_user == "" &&
      FLAGS_warble == "" && FLAGS_reply == -1 && FLAGS_follow == "" &&
      FLAGS_read == -1 && !FLAGS_profile) {
    command_line->Hook();
  } else if (FLAGS_registeruser != "" && !FLAGS_hook && FLAGS_user == "" &&
             FLAGS_warble == "" && FLAGS_reply == -1 && FLAGS_follow == "" &&
             FLAGS_read == -1 && !FLAGS_profile) {
    command_line->RegisterUser(FLAGS_registeruser);
  } else if (FLAGS_user != "" && !FLAGS_hook && FLAGS_registeruser == "") {
    if (command_line->CheckUser(FLAGS_user)) {
      if (FLAGS_warble != "") {
        command_line->Warble(FLAGS_user, FLAGS_warble, FLAGS_reply);
      }
      if (FLAGS_follow != "") {
        command_line->Follow(FLAGS_user, FLAGS_follow);
      }
      if (FLAGS_read != -1) {
        command_line->Read(FLAGS_read);
      }
      if (FLAGS_profile) {
        command_line->Profile(FLAGS_user);
      }
      if (FLAGS_stream != "") {
        // validate hashtag
        if (FLAGS_stream[0] != '#') {
          std::cout << "Stream must be called with a hashtag. You may need to "
                       "put quotes around it.\nExample: --stream \"#hello\"\n";
        } else {
          for (char c : FLAGS_stream) {
            if (isspace(c)) {
              std::cout << "Hashtags cannot have spaces\n";
              return 1;
            }
          }
          command_line->Stream(FLAGS_stream);
        }
      }
      if (FLAGS_warble == "" && FLAGS_follow == "" && FLAGS_read == -1 &&
          !FLAGS_profile && FLAGS_stream == "") {
        std::cout << "User flag must be used with other flags." << std::endl;
      }
    } else {
      std::cout << "User " << FLAGS_user << " does not exist." << std::endl;
    }
  } else {
    std::cout << "Invalid combination of flags." << std::endl;
  }
  s.join();
  return 0;
}
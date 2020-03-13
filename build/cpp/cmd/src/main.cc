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

int main(int argc, char **argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  google::InitGoogleLogging(argv[0]);
  cmd::CommandLine command_line;
  // Hook
  if (FLAGS_hook && FLAGS_registeruser == "" && FLAGS_user == "" &&
      FLAGS_warble == "" && FLAGS_reply == -1 && FLAGS_follow == "" &&
      FLAGS_read == -1 && !FLAGS_profile) {
    command_line.Hook();
  } else if (FLAGS_registeruser != "" && !FLAGS_hook && FLAGS_user == "" &&
             FLAGS_warble == "" && FLAGS_reply == -1 && FLAGS_follow == "" &&
             FLAGS_read == -1 && !FLAGS_profile) {
    command_line.RegisterUser(FLAGS_registeruser);
  } else if (FLAGS_user != "" && !FLAGS_hook && FLAGS_registeruser == "") {
    if (command_line.CheckUser(FLAGS_user)) {
      if (FLAGS_warble != "") {
        command_line.Warble(FLAGS_user, FLAGS_warble, FLAGS_reply);
      }
      if (FLAGS_follow != "") {
        command_line.Follow(FLAGS_user, FLAGS_follow);
      }
      if (FLAGS_read != -1) {
        command_line.Read(FLAGS_read);
      }
      if (FLAGS_profile) {
        command_line.Profile(FLAGS_user);
      } else {
        std::cout << "User flag must be used with other flags." << std::endl;
      }
    } else {
      std::cout << "User " << FLAGS_user << " does not exist." << std::endl;
    }
  } else {
    std::cout << "Invalid combination of flags." << std::endl;
  }
}
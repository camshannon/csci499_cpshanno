#include "cmd.h"

// command line tools constructor
cmd::CommandLine::CommandLine() {
  func_client_ = new func_client::FuncServiceClient(grpc::CreateChannel(
      "localhost:50000", grpc::InsecureChannelCredentials()));
}

// command line tools destructor
cmd::CommandLine::~CommandLine() { delete func_client_; }

// hooks the appropriate function ids and functions
void cmd::CommandLine::Hook() {
  func_client_->Hook(0, "Registeruser");
  func_client_->Hook(1, "Warble");
  func_client_->Hook(2, "Follow");
  func_client_->Hook(3, "Read");
  func_client_->Hook(4, "Profile");
  func_client_->Hook(1, "Hashtags");
  std::cout << "Warble functions/streams successfully hooked." << std::endl;
}

// check if a user for the username exists
bool cmd::CommandLine::CheckUser(const std::string &username) {
  ProfileRequest request;
  Any any;
  request.set_username(username);
  any.PackFrom(request);
  const auto &result = func_client_->Event(4, any);
  if (result) {
    return true;
  }
  return false;
}

// checks if a warble for the id exists
bool cmd::CommandLine::CheckWarble(const int64_t &id) {
  ReadRequest request;
  Any any;
  request.set_warble_id(std::to_string(id));
  any.PackFrom(request);
  const auto &result = func_client_->Event(3, any);
  if (result) {
    return true;
  }
  return false;
}

// checks if a user already follows another user
bool cmd::CommandLine::CheckFollow(const std::string &username,
                                   const std::string &to_follow) {
  ProfileRequest request;
  ProfileReply reply;
  Any any;
  request.set_username(username);
  any.PackFrom(request);
  const auto &result = func_client_->Event(4, any);
  result->UnpackTo(&reply);
  for (int i = 0; i < reply.following().size(); i++) {
    if (to_follow == reply.following()[i]) {
      return false;
    }
  }
  return true;
}

// registers the user with the username
void cmd::CommandLine::RegisterUser(const std::string &username) {
  if (!CheckUser(username)) {
    RegisteruserRequest request;
    request.set_username(username);
    Any any;
    any.PackFrom(request);
    const auto &result = func_client_->Event(0, any);
    if (result) {
      std::cout << "Successfully registered user " + username << "."
                << std::endl;
    } else {
      std::cout << "Error while registering user " << username << "."
                << std::endl;
    }
  } else {
    std::cout << "User " << username << " already exists." << std::endl;
  }
}

// creates the warble with username, text, and parent_id
void cmd::CommandLine::Warble(const std::string &username,
                              const std::string &text,
                              const int64_t &parent_id) {
  WarbleRequest request;
  WarbleReply reply;
  Any any;
  request.set_username(username);
  request.set_text(text);
  srand(time(NULL));
  int rand_id = rand();
  while (CheckWarble(rand_id)) {
    rand_id = rand();
  }
  request.set_id(std::to_string(rand_id));
  if (parent_id != -1) {
    if (CheckWarble(parent_id)) {
      request.set_parent_id(std::to_string(parent_id));
    } else {
      std::cout << "Parent warble " << parent_id << " does not exist."
                << std::endl;
    }
  }
  any.PackFrom(request);
  const auto &result = func_client_->Event(1, any);
  if (result) {
    result->UnpackTo(&reply);
    std::cout << "(" << reply.warble().username() << ", "
              << reply.warble().text() << ", " << reply.warble().id() << ", "
              << reply.warble().parent_id() << ", "
              << reply.warble().timestamp().seconds() << ", "
              << reply.warble().timestamp().useconds() << ")" << std::endl;
  } else {
    std::cout << "Error while creating warble." << std::endl;
  }
}

// follows a user
void cmd::CommandLine::Follow(const std::string &username,
                              const std::string &to_follow) {
  if (CheckUser(to_follow)) {
    if (CheckFollow(username, to_follow)) {
      FollowRequest request;
      Any any;
      request.set_username(username);
      request.set_to_follow(to_follow);
      any.PackFrom(request);
      const auto &result = func_client_->Event(2, any);
      if (result) {
        std::cout << "User " << username << " successfully followed user "
                  << to_follow << "." << std::endl;
      } else {
        std::cout << "Error while following user " << to_follow << std::endl;
      }
    } else {
      std::cout << "User " << username << " already follows user " << to_follow
                << "." << std::endl;
    }
  } else {
    std::cout << "User " << to_follow << " to follow does not exist."
              << std::endl;
  }
}

// recursively reads a thread starting from a warble
void cmd::CommandLine::Read(const int64_t &id) {
  if (CheckWarble(id)) {
    ReadHelper(id, 0);
  } else {
    std::cout << "Warble " << id << " could not be found." << std::endl;
  }
}

// helper function to recurse through thread
void cmd::CommandLine::ReadHelper(const int64_t &id, int count) {
  ReadRequest request;
  Any any;
  request.set_warble_id(std::to_string(id));
  any.PackFrom(request);
  const auto &result = func_client_->Event(3, any);
  ReadReply reply;
  result->UnpackTo(&reply);
  for (int i = 0; i < count; i++) {
    std::cout << " ";
  }
  std::cout << "(" << reply.warbles()[0].username() << ", "
            << reply.warbles()[0].text() << ", " << reply.warbles()[0].id()
            << ", " << reply.warbles()[0].parent_id() << ", "
            << reply.warbles()[0].timestamp().seconds() << ", "
            << reply.warbles()[0].timestamp().useconds() << ")" << std::endl;
  if (reply.warbles().size() == 1) {
    return;
  }
  for (int i = 1; i < reply.warbles().size(); i++) {
    ReadHelper(std::stoi(reply.warbles()[i].id()), ++count);
    --count;
  }
}

// shows a user's followers and following
void cmd::CommandLine::Profile(const std::string &username) {
  ProfileRequest request;
  ProfileReply reply;
  Any any;
  request.set_username(username);
  any.PackFrom(request);
  const auto &result = func_client_->Event(4, any);
  result->UnpackTo(&reply);
  std::cout << "Followers: ";
  for (int i = 1; i < reply.followers().size(); i++) {
    std::cout << reply.followers()[i];
    if (i < reply.followers().size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
  std::cout << "Following: ";
  for (int i = 1; i < reply.following().size(); i++) {
    std::cout << reply.following()[i];
    if (i < reply.following().size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}

void cmd::CommandLine::StreamCallback(const std::string &msg) {
  std::cout << "in callback" << std::endl;
  warble::Warble w;
  w.ParseFromString(msg);
  time_t tp = w.timestamp().seconds();
  auto timestr = asctime(gmtime(&tp));
  std::cout << "warble from " << w.username() << " at " << timestr << std::endl;
  std::cout << std::endl << w.text() << std::endl << std::endl;
}

// subscribes to a stream that prints new warbles containing `hashtag`
void cmd::CommandLine::Stream(const std::string &hashtag) {
  std::cout << "Here's what people are saying about " << hashtag << " ...\n\n";
  warble::StreamRequest request;
  request.set_hashtag(hashtag);
  Any args;
  args.PackFrom(request);
  // subscribe to the stream
  auto cb = [this](const std::string &msg) { this->StreamCallback(msg); };
  if (!func_client_->Stream("Hashtags", args, cb)) { 
    std::cout << "\nLost connection to the stream.\n";
  }
}
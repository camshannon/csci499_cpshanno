#include <chrono>
#include <functional>
#include <optional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include <glog/logging.h>

#include "warble.pb.h"

using google::protobuf::Any;
using warble::FollowReply;
using warble::FollowRequest;
using warble::ProfileReply;
using warble::ProfileRequest;
using warble::ReadReply;
using warble::ReadRequest;
using warble::RegisteruserReply;
using warble::RegisteruserRequest;
using warble::Timestamp;
using warble::Warble;
using warble::WarbleReply;
using warble::WarbleRequest;

namespace warble_functions {
  // gets the func_map
  // @return the func_map from string to pairs of request and reply functions
  const std::unordered_map<
      std::string,
      std::pair<std::function<std::vector<
                    std::tuple<int, std::string, std::string>>(Any)>,
                std::function<Any(std::vector<std::vector<std::string>>)>>> &
  GetFuncMap();

  // receives a register user request as an any and packages it for func
  // @param: the any containing the register user request
  // @return: the vector allowing for multiple calls to func
  //  vector will have size 3
  //  the int 0 indicates a put request to func
  //  the first string indicates the user's username, username_following, and
  //  username_followers the second string indicates the user's username
  const std::vector<std::tuple<int, std::string, std::string>>
  RegisteruserRequestPackager(const Any &any);

  // receives a placeholder 2D vector and returns the register user reply
  // @param: the vector allowing for multiple values to be returned
  //  the 2D vector will be a placeholder as the register user reply is
  //  indicated by the GRPC status
  // @return: the empty register user reply
  const Any RegisteruserReplyPackager(
      const std::vector<std::vector<std::string>> &result);

  // receives a warble request as an any and packages it for func
  // @param: the any containing the warble request
  // @return: the vector allows for multiple calls to func
  //  vector will have size 1 or 2 depending on if the warble has a parent
  //  the int value 1 indicates a put request to func
  //  the first string indicates the id of the warble and the parent id of the
  //  warble the second string indicates the serialized warble
  const std::vector<std::tuple<int, std::string, std::string>>
  WarbleRequestPackager(const Any &any);

  // receives a warble and packages it in a warble reply for the frontend
  // @param: the vector allowing for multiple values to be returned
  //  the 2D vector will hold 1 element, the desired warble output
  // @return the warble reply containing the accessed warble
  static const Any
  WarbleReplyPackager(const std::vector<std::vector<std::string>> &result);

  // receives a follow request as an any and packages it for func
  // @return: A vector allowing for multiple calls to func
  //  vector will have size 2
  //  the int value 0 indicates a put request to func
  //  the first string indicates the username_following and to_follow_following
  //  the second string indicates the to_follow for username and username for
  //  to_follow
  const std::vector<std::tuple<int, std::string, std::string>>
  FollowRequestPackager(const Any &any);

  // receives a placeholder 2D vector and returns the follow reply
  // @param: the vector allowing for multiple values to be returned
  //  the 2D vector will be a placeholder as the register user reply is
  //  indicated by the GRPC status
  // @return: the empty follow reply
  const Any
  FollowReplyPackager(const std::vector<std::vector<std::string>> &result);

  // receives a follow request as an any and packages it for func
  // @return: A vector allowing for multiple calls to func
  //  vector will have size 2
  //  the int value 1 indicates a get request to func
  //  the first string indicates the username_following and to_follow_following
  //  the second string indicates the to_follow for username and username for
  //  to_follow
  const std::vector<std::tuple<int, std::string, std::string>>
  ReadRequestPackager(const Any &any);

  // receives a vector containing all the warbles in reply to the requested
  // warble
  // @param: the vector allowing for multiple values to be returned
  //  the 2D vector will be a placeholder as the register user reply is
  //  indicated by the GRPC status
  // @return: the empty follow reply
  const Any
  ReadReplyPackager(const std::vector<std::vector<std::string>> &result);

  // receives a profile request as an any and packages it for func
  // @return: A vector allowing for multiple calls to func
  //  vector will have size 3
  //  the int value 1 indicates a get request to func
  //  the first string indicates the username, username_following,
  //  username_followers the second string is a placeholder and will be empty
  const std::vector<std::tuple<int, std::string, std::string>>
  ProfileRequestPackager(const Any &any);

  // receives a vector containing the two vectors of the user's followers and
  // followings
  // @param: the vector allowing for multiple values to be returned
  //  the 2D vector will have three vectors containing the username,
  //  username_followers, and username_followings
  // @return: the profile reply containing the two vectors of the user's
  // followers and followings
  //  empty if username is not found
  const Any
  ProfileReplyPackager(const std::vector<std::vector<std::string>> &result);

  // the unordered map for associating function names with functions
  //  function names map to request function and reply function
  const std::unordered_map<
      std::string,
      std::pair<std::function<std::vector<
                    std::tuple<int, std::string, std::string>>(Any)>,
                std::function<Any(std::vector<std::vector<std::string>>)>>>
      func_map_;
  // a counter for the warble id
  int warble_count_;
} // namespace warble_functions
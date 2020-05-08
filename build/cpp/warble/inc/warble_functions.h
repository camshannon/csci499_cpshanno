#include <glog/logging.h>

#include <chrono>
#include <functional>
#include <optional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

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

// request vector type for func calls
//  the vector size is the number of calls being made to func
//  the int indicates the request type
//   0 for puts, 1 for gets, 2 for removes, 3 for stream notifications, and -1
//   for an error
//  the first string indicates the key, or streamID if the int is 3
//  the second string is the value for puts or empty string
using request_vector = std::vector<std::tuple<int, std::string, std::string>>;

// result vector type for returning values
//  the outer vector indicates seperate values being returned
//  the inner vector indicates values of the same key being returned
using reply_vector = std::vector<std::vector<std::string>>;

// map type for function names to request/reply pairs
using function_mapping = std::unordered_map<
    std::string,
    std::pair<std::function<
                  std::vector<std::tuple<int, std::string, std::string>>(Any)>,
              std::function<Any(std::vector<std::vector<std::string>>)>>>;

// map type for stream handler functions
using stream_mapping = std::unordered_map<
    std::string, std::function<std::vector<std::string>(
                     std::vector<std::pair<std::string, Any>>, std::string)>>;

namespace warble_functions {

// receives a register user request as an any and packages it for func
//  @param: RegisterUserRequest any
//  @return: request vector
//   size: 2
//   int: 0 indicating put
//   string1: username_following and username_followers
//   string2: empty string
const request_vector RegisteruserRequestPackager(const Any &any);

// receives a placeholder 2D vector and returns the register user reply
// @param: reply vector
//   empty as success is indicated by gRPC status
// @return: RegisterUserReply any
const Any RegisteruserReplyPackager(const reply_vector &result);

// receives a warble request as an any and packages it for func
// @param:  WarbleRequest any
// @return: request vector
//   size: 1 or 2 depending on if the warble has a parent
//   int: 1 indicating get
//   string1: the id of the warble and parent id of the warble respectively
//   string2: the serialized warble
const request_vector WarbleRequestPackager(const Any &any);

// receives a warble and packages it in a warble reply for the frontend
// @param: reply vector
//   holds 1 element, the desired warble output
// @return: the warble reply any containing the accessed warble
const Any WarbleReplyPackager(const reply_vector &result);

// receives a follow request as an any and packages it for func
// @param: FollowRequest any
// @return: request vector
//    size: 2
//    int: 0 indicating put
//    string1: username_following and to_follow_following
//    string2: to_follow and username respectively
const request_vector FollowRequestPackager(const Any &any);

// receives a placeholder 2D vector and returns the follow reply
// @param: reply vector
//   empty as success is indicated by gRPC status
// @return: FollowReply any
const Any FollowReplyPackager(const reply_vector &result);

// receives a read request as an any and packages it for func
// @param: ReadRequest any
// @return: request vector
//   size: 1
//   int: 1 indicating get
//   string1: warble_warble_id
//   string2: empty string
const request_vector ReadRequestPackager(const Any &any);

// receives a vector containing all the warbles in reply to the requested
// warble and packages it in a read reply for the frontend
// @param: reply vector
//   holds the vector of warbles in reply to the requested warble
// @return: ReadReply any
const Any ReadReplyPackager(const reply_vector &result);

// receives a profile request as an any and packages it for func
// @param: ProfileRequest any
// @return: request vector
//   size: 2
//   int1: 1 indicating get
//   string1: username, username_following
//   string2: empty string
const request_vector ProfileRequestPackager(const Any &any);

// receives a vector containing the two vectors of the user's followers and
// followings
// @param: reply vector
//   holds two vectors containing the username_followers and username_followings
// @return: ProfileReply any
const Any ProfileReplyPackager(const reply_vector &result);

// returns a list of clients that should be streamed given the streaming payload
const std::vector<std::string> StreamHandler(
    const std::vector<std::pair<std::string, Any>> &clients,
    const std::string &warble);

// parses the text for all hashtags, defined as the string of
// contiguous non-whitespace characters that follow a '#'
const std::vector<std::string> FindHashtags(const std::string &text);

// the unordered map for associating function names with functions
//  function names map to request function and reply function
const function_mapping func_map{
    {"Registeruser",
     std::make_pair(RegisteruserRequestPackager, RegisteruserReplyPackager)},
    {"Warble", std::make_pair(WarbleRequestPackager, WarbleReplyPackager)},
    {"Follow", std::make_pair(FollowRequestPackager, FollowReplyPackager)},
    {"Read", std::make_pair(ReadRequestPackager, ReadReplyPackager)},
    {"Profile", std::make_pair(ProfileRequestPackager, ProfileReplyPackager)}};

const stream_mapping stream_map{{"Hashtags", StreamHandler}};

}  // namespace warble_functions
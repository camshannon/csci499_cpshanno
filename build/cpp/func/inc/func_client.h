#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include <map>
#include <memory>
#include <string>

#include "func.grpc.pb.h"
#include "func.pb.h"

using func::DisconnectReply;
using func::DisconnectRequest;
using func::EventReply;
using func::EventRequest;
using func::FuncService;
using func::HookReply;
using func::HookRequest;
using func::StreamRequest;
using func::UnhookReply;
using func::UnhookRequest;
using google::protobuf::Any;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::Status;

namespace func_client {

// the func client
class FuncServiceClient {
 public:
  // func client constructor
  FuncServiceClient(std::shared_ptr<Channel> channel)
      : stub_(FuncService::NewStub(channel)) {}

  // associates this type of event with the given function for future execution
  // by Func
  void Hook(const int32_t &event_type, const std::string &event_function);

  // unregisters an event of the given type, if registered.  has no effect if
  // already unregistered.
  void Unhook(const int32_t &event_type);

  // represents an arriving event of the given type with an arbitrary message
  // payload
  const std::optional<Any> Event(const int32_t &event_type, const Any &payload);

  // subscribes to a blocking stream, preventing any other calls from the client
  const bool Stream(const std::string &stream_type, const Any &payload,
                    const std::function<void(const std::string &)> &,
                    const std::function<void(const std::string &)> &);

  // disconnects client from its stream type
  void Disconnect(const std::string &id, const std::string &stream_type);

 private:
  // The client object making unary RPC calls to the func server
  std::unique_ptr<FuncService::Stub> stub_;
};
}  // namespace func_client
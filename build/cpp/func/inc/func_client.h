#include <memory>
#include <string>

#include <glog/logging.h>
#include <grpcpp/grpcpp.h>

#include "func.grpc.pb.h"
#include "func.pb.h"

using func::EventReply;
using func::EventRequest;
using func::FuncService;
using func::HookReply;
using func::HookRequest;
using func::UnhookReply;
using func::UnhookRequest;
using google::protobuf::Any;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

namespace func_client {

// the key value store client
class FuncServiceClient {
public:
  // func client constructor
  FuncServiceClient(std::shared_ptr<Channel> channel)
      : stub_(FuncService::NewStub(channel)) {}

  // associates this type of event with the given function for future execution
  // by Func
  void hook(const int32_t &event_type, const std::string &event_function);

  // unregisters an event of the given type, if registered.  has no effect if
  // already unregistered.
  void unhook(const int32_t &event_type);

  // represents an arriving event of the given type with an arbitrary message
  // payload
  std::optional<Any> event(const int32_t &event_type, Any &payload);

private:
  // The client object making RPC calls to the func server
  std::unique_ptr<FuncService::Stub> stub_;
};
} // namespace func_client
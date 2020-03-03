#include "func.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;
using grpc::StatusCode;
using google::protobuf::Any;
using func::HookRequest;
using func::HookReply;
using func::UnhookRequest;
using func::UnhookReply;
using func::EventRequest;
using func::EventReply;
using func::FuncService;

namespace func_server {

// the key value store server
class FuncServiceImpl final : public FuncService::Service {
public:
  // associates this type of event with the given function for future execution by Func
  Status hook(ServerContext *context, const HookRequest *request,
              HookReply *reply) override;

  // unregisters an event of the given type, if registered. has no effect if already unregistered.
  Status unhook(ServerContext *context, const UnhookRequest *request,
                UnhookReply *reply) override;

  // represents an arriving event of the given type with an arbitrary message payload
  Status event(ServerContext *context, const EventRequest *request,
                EventReply *reply) override;

  // sets the pre-known map from function names to functions
  void SetFuncMap(const std::unordered_map<std::string, std::function<Any(Any)>>& func_map);

private:
  // the func for the for server
  func::Func func_; 
};

// runs the server on port 50000
void RunServer();
} // namespace func_server
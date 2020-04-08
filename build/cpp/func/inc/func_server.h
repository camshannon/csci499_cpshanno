#include "func.h"
#include "warble_functions.h"

using func::EventReply;
using func::EventRequest;
using func::FuncService;
using func::HookReply;
using func::HookRequest;
using func::UnhookReply;
using func::UnhookRequest;
using google::protobuf::Any;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReaderWriter;
using grpc::Status;
using grpc::StatusCode;

namespace func_server {

// the key value store client
class FuncServiceImpl final : public FuncService::Service {
public:
  // associates this type of event with the given function for future execution
  // by Func
  Status hook(ServerContext *context, const HookRequest *request,
              HookReply *reply) override;

  // unregisters an event of the given type, if registered. has no effect if
  // already unregistered.
  Status unhook(ServerContext *context, const UnhookRequest *request,
                UnhookReply *reply) override;

  // represents an arriving event of the given type with an arbitrary message
  // payload
  Status event(ServerContext *context, const EventRequest *request,
               EventReply *reply) override;

  // sets the pre-known map from function names to functions
  void SetFuncMap(
      const std::unordered_map<
          std::string,
          std::pair<std::function<std::vector<
                        std::tuple<int, std::string, std::string>>(Any)>,
                    std::function<Any(std::vector<std::vector<std::string>>)>>>
          &func_map);

private:
  // the func for the for server
  func::Func func_;
};

// runs the server on port 50000
void RunServer(
    const std::unordered_map<
        std::string,
        std::pair<std::function<std::vector<
                      std::tuple<int, std::string, std::string>>(Any)>,
                  std::function<Any(std::vector<std::vector<std::string>>)>>>
        &func_map);
} // namespace func_server
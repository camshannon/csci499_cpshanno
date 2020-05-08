#include "func.h"

// func constructor
func::Func::Func() {
  kvstore_client_ = new kvstore_client::KeyValueStoreClient(grpc::CreateChannel(
      "localhost:50001", grpc::InsecureChannelCredentials()));
}

// func destructor
func::Func::~Func() { delete kvstore_client_; }

// puts a new element into func_map_ or updates the value at event_type
void func::Func::Hook(const int32_t &event_type,
                      const std::string &event_function) {
  std::unique_lock lock(mutex_);
  const auto &it = func_map_.find(event_function);
  if (it != func_map_.end()) {
    event_map_[event_type] = it->second;
  }
}

// removes the element with event_type if registered
void func::Func::Unhook(const int32_t &event_type) {
  std::unique_lock lock(mutex_);
  event_map_.erase(event_type);
}

// executes the request and reply functions with the specified event type
const std::optional<Any> func::Func::Event(const int32_t &event_type,
                                           const Any &payload) {
  std::shared_lock lock(mutex_);
  const auto &storage_requests = (event_map_[event_type].first)(payload);
  reply_vector result;
  for (const auto &storage_request : storage_requests) {
    const auto &request_type = std::get<0>(storage_request);
    const auto &key = std::get<1>(storage_request);
    const auto &value = std::get<2>(storage_request);
    std::cout << request_type << " :: " << key << std::endl;
    std::vector<std::string> values;
    // put request
    if (request_type == 0) {
      kvstore_client_->put(key, value);
      values.push_back(value);
    }
    // get request
    else if (request_type == 1) {
      const auto &optional_values = kvstore_client_->get(key);
      // if key was found, set value vector to the found value
      if (optional_values) {
        values = *optional_values;
      } else {
        return {};
      }
    }
    // remove request
    else if (request_type == 2) {
      kvstore_client_->remove(key);
      values.push_back(value);
    }
    
    // stream notification
    else if (request_type == 3) {
      // get clients subscribed to this stream type
      std::cout << "got a stream request_type" << std::endl;
      const auto &optional_values = kvstore_client_->get("stream_"+key+"_");
      if (optional_values) {
        std::cout << "found keys of proper type\n";
        std::vector<std::pair<std::string, Any>> clients;
        for (std::string id : *optional_values) {
          std::cout << "client id " << id << std::endl;
          const auto &op_args = kvstore_client_->get("stream_args_"+id+"_");
          if (op_args && op_args->size()) {
            Any args;
            args.ParseFromString(op_args->at(0));
            // add the clients and their arguments to the list
            clients.push_back(std::make_pair(id, args));
          }
        }
        // call the stream handler and pass it clients
        auto selected = stream_map_[key](clients, value);
        // put the warble for the selected clients
        for (auto id : selected) SetStreamSignal(id, value);
      }
   }
    // error request
    else if (request_type == -1) {
      return {};
    }
    if (request_type != 3) result.push_back(values);
  }
  return {(event_map_[event_type].second)(result)};
}

// sets the pre-known map from function names to functions
void func::Func::SetFuncMap(
    const function_mapping
        &func_map) {
  func_map_ = func_map;
}

void func::Func::SetStreamMap(const stream_mapping &stream_map) {
  stream_map_ = stream_map;
}

// gets the event map
//  for testing purposes
event_mapping
func::Func::GetEventMap() {
  return event_map_;
}

// subscribes a client to a stream internally within func
void func::Func::AddStreamClient(const std::string &client_id, const std::string &stream_type, const Any &args) {
  kvstore_client_->put("stream_"+stream_type+"_", client_id);
  kvstore_client_->put("stream_args_"+client_id+"_", args.SerializeAsString());
}

// removes client from its stream
void func::Func::RemoveStreamClient(const std::string &client_id, const std::string &stream_type) {
  kvstore_client_->remove("stream_"+stream_type+"_");
  kvstore_client_->remove("stream_args_"+client_id+"_");
}

// returns true if this client is still attached to its stream
bool func::Func::ClientExists(const std::string &client_id, const std::string &stream_type) {
  auto id = kvstore_client_->get("stream_"+stream_type+"_");
  if (!id) return false;
  return (std::find(id->begin(), id->end(), client_id) != id->end());
}

// mutator method for the stream signal
void func::Func::SetStreamSignal(const std::string &client_id, const std::string &msg) {
  kvstore_client_->put("stream_"+client_id+"_", msg);
}

// clears the stream signal for a client
void func::Func::ClearStreamSignal(const std::string &client_id) {
  kvstore_client_->remove("stream_"+client_id+"_");
}

// returns a message that the server needs to send to the given client over a stream
// or nothing, if there isn't anything to send
const std::optional<Any> func::Func::StreamSignal(const std::string &client_id) {
  std::cout << client_id << std::endl;
  auto values = kvstore_client_->get("stream_"+client_id+"_");
  if (values && values->size()) {
    Any payload;
    if (payload.ParseFromString(values->at(0))) {
      return payload;
    } else {
      return std::nullopt;
    }
  } else {
    return std::nullopt;
  }
}
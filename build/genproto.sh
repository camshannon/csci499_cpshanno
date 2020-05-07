mkdir gen
protoc -I protos --cpp_out=gen protos/warble.proto protos/kvstore.proto protos/func.proto
protoc -I protos --grpc_out=gen --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` protos/kvstore.proto protos/func.proto

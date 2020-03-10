# cs499
Robust Software Design and Implementation

$ cd project
$ GLOG_logtostderr=1 ./cpp/kvstore/kvstore_server
$ GLOG_logtostderr=1 ./cpp/kvstore/kvstore_client

clang-format cpp/kvstore/kvstore_server
cpplint cpp/kvstore/kvstore_server

protoc -I protos --cpp_out=gen protos/warble.proto protos/kvstore.proto protos/func.proto

protoc -I protos --grpc_out=gen --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` protos/kvstore.proto protos/func.proto

valgrind --tool=memcheck --leak-check=yes ./cpp/warble/bin/warble_test
# cs499
Robust Software Design and Implementation

Introduction

Download and Installation

1. Download and install Vagrant v. 2.2.7 at https://www.vagrantup.com/downloads.html.

2. Add vagrant (C:HashiCorp\Vagrant\bin) to your PATH.

3. Download and install Oracle VM Virtualbox Manager v. 6.0.12 at https://www.virtualbox.org/wiki/Downloads.

4. Create a folder in your base directory named "Vagrant VMs."

5. Open the command prompt and run C:\Users\user>cd "Vagrant VMs"

6. Run C:\Users\user>vagrant box add ubuntu/bionic64

7. Run C:\Users\user>vagrant init ubuntu/bionic64

8. Run C:\Users\user>vagrant up

9. Go to Oracle VM Virtual Box Manager, open the VM, and press Show.

10. Login with username vagrant and password vagrant.

11. Run sudo apt-get update

12. Run sudo apt-get install desktop





$ GLOG_logtostderr=1 ./cpp/kvstore/kvstore_server
$ GLOG_logtostderr=1 ./cpp/kvstore/kvstore_client

clang-format cpp/kvstore/kvstore_server
cpplint cpp/kvstore/kvstore_server

protoc -I protos --cpp_out=gen protos/warble.proto protos/kvstore.proto protos/func.proto

protoc -I protos --grpc_out=gen --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` protos/kvstore.proto protos/func.proto

valgrind --tool=memcheck --leak-check=yes ./cpp/warble/bin/warble_test
# cs499
Robust Software Design and Implementation

Introduction

Warble. An application to allow for user's to post warbles and follow other users.

Download and Installation

1. Download and install Vagrant v. 2.2.7 at https://www.vagrantup.com/downloads.html.

2. Add vagrant (C:HashiCorp\Vagrant\bin) to your PATH

3. Download and install Oracle VM Virtualbox Manager v. 6.0.12 at https://www.virtualbox.org/wiki/Downloads.

4. Create a folder in your base directory named "Vagrant VMs"

5. Open the command prompt and run C:\Users\user>cd "Vagrant VMs"

6. Run C:\Users\user>vagrant box add ubuntu/bionic64

7. Run C:\Users\user>vagrant init ubuntu/bionic64

8. Run C:\Users\user>vagrant up

9. Go to Oracle VM Virtual Box Manager, open the VM, and press Show

10. Login with username vagrant and password vagrant

11. Run $ sudo apt-get update

12. Run $ sudo apt-get install ubuntu-desktop

13. (Optional) In Virtual Box Manager: increase base memory, processors, max video memory, and enable 3D acceleration

14. (Optional) In Virtual Box Manager: Settings, advanced, shared clipboard bidirectional

15. Restart the virtual machine

16. Run $ sudo apt-get install cmake to install cmake

17. Run $ sudo apt-get install libgflags-dev to install gflags

18. Run $ sudo apt-get install libgoogle-glog-dev to install glog

18. Run sudo $ apt-get install libgtest-dev
						 $ cd /usr/src/gtest
						 $ sudo cmake CMakeLists.txt
						 $ sudo make
						 $ sudo cp *.a /usr/lib
						 to install gtest

19. Run $ sudo apt-get install libprotobuf-dev protobuf-compiler to install protoc

20. Run $ sudo apt-get install build-essential autoconf libtool pkg-config to install pkg-config

21. Run $ sudo apt-get install libunwind-dev to install unwinder

22. Run $ sudo snap install go --classic to install Go

23. Run $ sudo apt-get install autoconf automake libtool curl make g++ unzip

24. Run $ git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc in Desktop

25. Run $ cd grpc
 				$ git submodule update --init
 				$ make
 				to install gRPC

26. Run $ git clone https://github.com/camshannon/csci499_cpshanno.git in Desktop
				$ cd csci499_cpshanno/build
				$ mkdir gen
				$ protoc -I protos --cpp_out=gen protos/warble.proto protos/kvstore.proto protos/func.proto
				$ protoc -I protos --grpc_out=gen --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` protos/kvstore.proto protos/func.proto
				to build the generated protobuf and grpc files.

27. Place a bin folder in cpp/cmd, cpp/func, cpp/kvstore, and cpp/warble.

Running the Application

1. Get to directory csci499_cpshanno/build and run cmake .

2. Open 3 windows in tmux.

3. In one window, run $ make func_server
											$ cpp/func/bin/func_server

4. In another, run $ make kvstore_server
									 $ cpp/kvstore/bin/kvstore_server

5. The last window will be used to make our requests.
	 Begin by running $ make warble
	 									$ cpp/cmd/bin/warble --hook
	 									to hook the function calls.

6. From there,  the following tags may be used by the user.
	--registeruser <username>	Registers the given username
	--user <username>		Logs in as the given username
	--warble <warble text>	Creates a new warble with the given text
	--reply <reply warble id>	Indicates that the new warble is a reply to the given id
	--follow <username>		Starts following the given username
	--read <warble id>		Reads the warble thread starting at the given id
	--profile			Gets the user’s profile of following and followers

Optional

1. To see all logging information, run servers and application with
	 $ GLOG_logtostderr=1 beforehand.(EX: $ GLOG_logtostderr=1 cpp/func/bin/func_server)
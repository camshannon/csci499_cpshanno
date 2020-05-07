# cs499
Robust Software Design and Implementation

## Introduction

Warble. An application to allow for user's to post warbles and follow other users.

## Installation

1. Run `vagrant up` to provision the virtual machine.

2. Connect using `vagrant ssh`.

## Running the Application

1. Navigate to the `/vagrant/build` directory.

2. Run the following commands:
```
$ bash genproto.sh
$ cmake .
```

3. Open 3 windows in tmux.

4. In one window, run:
```
$ make func_server
$ ./bin/func_server
```

5. In another, run:
```
$ make kvstore_server
$ ./bin/kvstore_server
```

6. The last window will be used to make our requests. Begin by hooking the functions:
```
$ make warble
$ ./bin/warble --hook
```

7. From there, the following tags may be used by the user.

	`--registeruser <username>`: registers the given username

	`--user <username>`: logs in as the given username

	`--warble <warble text>`: creates a new warble with the given text

	`--reply <reply warble id>`: indicates that the new warble is a reply to the given id

	`--follow <username>`: starts following the given username

	`--read <warble id>`: reads the warble thread starting at the given id

	`--profile`: gets the user’s profile of following and followers

## Optional

To see all logging information, run servers and application with `GLOG_logtostderr`, for example:
```
$ GLOG_logtostderr=1 ./bin/func_server
```
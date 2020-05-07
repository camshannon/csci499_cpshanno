# -*- mode: ruby -*-
# vi: set ft=ruby :

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.
Vagrant.configure("2") do |config|
  # The most common configuration options are documented and commented below.
  # For a complete reference, please see the online documentation at
  # https://docs.vagrantup.com.

  # Every Vagrant development environment requires a box. You can search for
  # boxes at https://vagrantcloud.com/search.
  config.vm.box = "ubuntu/bionic64"

  # Disable automatic box update checking. If you disable this, then
  # boxes will only be checked for updates when the user runs
  # `vagrant box outdated`. This is not recommended.
  # config.vm.box_check_update = false

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine. In the example below,
  # accessing "localhost:8080" will access port 80 on the guest machine.
  # NOTE: This will enable public access to the opened port
  # config.vm.network "forwarded_port", guest: 80, host: 8080

  # Create a forwarded port mapping which allows access to a specific port
  # within the machine from a port on the host machine and only allow access
  # via 127.0.0.1 to disable public access
  # config.vm.network "forwarded_port", guest: 80, host: 8080, host_ip: "127.0.0.1"

  # Create a private network, which allows host-only access to the machine
  # using a specific IP.
  # config.vm.network "private_network", ip: "192.168.33.10"

  # Create a public network, which generally matched to bridged network.
  # Bridged networks make the machine appear as another physical device on
  # your network.
  # config.vm.network "public_network"

  # Share an additional folder to the guest VM. The first argument is
  # the path on the host to the actual folder. The second argument is
  # the path on the guest to mount the folder. And the optional third
  # argument is a set of non-required options.
  # config.vm.synced_folder "../data", "/vagrant_data"

  # Provider-specific configuration so you can fine-tune various
  # backing providers for Vagrant. These expose provider-specific options.
  # Example for VirtualBox:
  #
  config.vm.provider "virtualbox" do |vb|
  #   # Display the VirtualBox GUI when booting the machine
  #   vb.gui = true
  #
  #   # Customize the amount of memory on the VM:
  #   vb.memory = "1024"
      vb.customize ["guestproperty", "set", :id, "/VirtualBox/GuestAdd/VBoxService/--timesync-set-threshold", 10000 ]
  end
  #
  # View the documentation for the provider you are using for more
  # information on available options.

  # Enable provisioning with a shell script. Additional provisioners such as
  # Ansible, Chef, Docker, Puppet and Salt are also available. Please see the
  # documentation for more information about their specific syntax and use.
  config.vm.provision "shell", inline: <<-SHELL
    apt-get update
    apt-get install g++ make libgflags-dev libssl-dev -y
    git clone -b 'v3.17.2' https://github.com/kitware/cmake.git ~/cmake
    cd ~/cmake
    ./bootstrap
    make
    make install
    apt-get install libgtest-dev -y
    cd /usr/src/gtest
    cmake .
    make
    cp *.a /usr/lib
    git clone -b 'v0.4.0' http://github.com/google/glog ~/glog 
    cd ~/glog
    cmake -H. -Bbuild -G "Unix Makefiles"
    cmake --build build
    cmake --build build --target install
    apt-get install build-essential autoconf libtool pkg-config libunwind-dev automake unzip -y
    git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc ~/grpc
    cd ~/grpc
    git submodule update --init
    mkdir -p cmake/build
    cd cmake/build
    cmake -DgRPC_INSTALL=ON -DBUILD_SHARED_LIBS=ON ../..
    make
    make install
    cd ~
    rm -rf cmake glog grpc
    echo "export LD_LIBRARY_PATH=/usr/local/lib:${LD_LIBRARY_PATH}" >> /home/vagrant/.bashrc
  SHELL
end
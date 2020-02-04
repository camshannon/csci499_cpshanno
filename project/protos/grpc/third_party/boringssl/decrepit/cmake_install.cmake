# Install script for directory: /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/decrepit

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/bio/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/blowfish/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/cast/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/cfb/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/des/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/dh/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/dsa/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/evp/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/obj/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/rc4/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/ripemd/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/rsa/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/ssl/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/x509/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/decrepit/xts/cmake_install.cmake")

endif()

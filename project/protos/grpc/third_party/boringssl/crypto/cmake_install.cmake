# Install script for directory: /home/vagrant/Desktop/csci499_cpshanno/grpc/third_party/boringssl/crypto

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
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/stack/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/lhash/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/err/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/buf/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/base64/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/bytestring/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/pool/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/rc4/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/conf/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/chacha/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/poly1305/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/curve25519/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/digest_extra/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/cipher_extra/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/rand_extra/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/bio/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/bn_extra/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/obj/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/asn1/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/engine/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/dh/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/dsa/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/rsa_extra/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/ec_extra/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/ecdh/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/ecdsa_extra/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/cmac/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/evp/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/hkdf/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/pem/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/x509/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/x509v3/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/pkcs7/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/pkcs8/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/test/cmake_install.cmake")
  include("/home/vagrant/Desktop/csci499_cpshanno/project/protos/grpc/third_party/boringssl/crypto/fipsmodule/cmake_install.cmake")

endif()

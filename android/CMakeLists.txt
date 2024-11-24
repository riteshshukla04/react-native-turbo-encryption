cmake_minimum_required(VERSION 3.4.1)
project(TurboEncryption)

set (CMAKE_VERBOSE_MAKEFILE ON)


add_library(react-native-turbo-encryption           
            STATIC
            ../cpp/NativeTurboEncryptionTurboModule.cpp
            ../cpp/tinyaes/aes.c
            ../cpp/tinyaes/aes.h
            ../cpp/tinyaes/aes.hpp
            ../cpp/AESWrapper.cpp
            ../cpp/AESWrapper.hpp
)

target_include_directories(react-native-turbo-encryption
        PUBLIC
        ../cpp
)


target_include_directories(react-native-turbo-encryption
        PUBLIC
        ../cpp/tinyaes
)


find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )




target_link_libraries(react-native-turbo-encryption
        jsi
        ${log-lib}
        react_codegen_RNTurboEncryptionSpec
)

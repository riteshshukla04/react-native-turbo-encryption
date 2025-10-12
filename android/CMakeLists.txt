project(turboencryption)
cmake_minimum_required(VERSION 3.9.0)

set(PACKAGE_NAME turboencryption)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)

# Find all C++ files (shared and platform specifics)
file(GLOB_RECURSE shared_files RELATIVE ${CMAKE_SOURCE_DIR}
        "../cpp/**.cpp"
)
file(GLOB_RECURSE android_files RELATIVE ${CMAKE_SOURCE_DIR}
        "src/main/cpp/**.cpp"
)

# Define C++ library and add all sources
add_library(${PACKAGE_NAME} SHARED 
    src/main/cpp/cpp-adapter.cpp
    ../cpp/TurboEncryption.cpp
    ../cpp/tinyaes/aes.c
     ../cpp/tinyaes/aes.h
     ../cpp/tinyaes/aes.hpp
     ../cpp/AESWrapper.cpp
     ../cpp/AESWrapper.hpp
)


include(${CMAKE_SOURCE_DIR}/../nitrogen/generated/android/turboencryption+autolinking.cmake)


target_include_directories(${PACKAGE_NAME}
        PUBLIC
        ../cpp/tinyaes
)


# Set up local includes
include_directories(
        "src/main/cpp"
        "../cpp"
)
find_library(LOG_LIB log)

# Link all libraries together
target_link_libraries(
        ${PACKAGE_NAME}
        ${LOG_LIB}
        android # <-- Android core
)

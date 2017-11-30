cmake_minimum_required(VERSION 3.8)
project(gomoku)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES source/main.cpp include/Protocol.hpp)

include_directories(include)
add_executable(gomoku ${SOURCE_FILES})
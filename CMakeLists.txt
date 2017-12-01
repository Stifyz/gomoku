cmake_minimum_required(VERSION 3.8)
project(gomoku)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES source/main.cpp include/Protocol.hpp include/Game.hpp source/Game.cpp source/Protocol.cpp include/Brain.hpp source/Brain.cpp include/Application.hpp include/AI.hpp source/AI.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(include)
add_executable(gomoku ${SOURCE_FILES})
target_link_libraries(gomoku pthread)

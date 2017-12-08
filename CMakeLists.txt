cmake_minimum_required(VERSION 3.4)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -std=c++11 -Wall")

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_COMPILER C:/MinGW/bin/gcc.exe)
set(CMAKE_CXX_COMPILER C:/MinGW/bin/g++.exe)

project(gomoku)

set(SOURCE_FILES source/main.cpp include/Protocol.hpp include/Game.hpp source/Game.cpp source/Protocol.cpp include/Brain.hpp source/Brain.cpp include/Application.hpp include/AI.hpp source/AI.cpp include/MyMultiset.hpp include/Info.h source/Application.cpp)

include_directories(include)
add_executable(pbrain-GroMoCrew ${SOURCE_FILES})
#target_link_libraries(pbrain-GroMoCrew pthread)

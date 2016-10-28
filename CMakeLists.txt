cmake_minimum_required(VERSION 3.5)
project(allocator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(src)

add_executable(set_test example/set_test.cpp)
cmake_minimum_required(VERSION 3.6)
project(ostringstream_test)

set(PROJECT_BINARY_DIR "./build")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(ost_test main.cpp)

cmake_minimum_required(VERSION 3.6)
project(libuv_hello)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

link_libraries(/usr/local/Cellar/libuv/HEAD-a62f8ce/lib/libuv.a)
include_directories(/usr/local/Cellar/libuv/HEAD-a62f8ce/include)

add_executable(libuv_hello main.cpp /usr/local/include/node/uv.h)

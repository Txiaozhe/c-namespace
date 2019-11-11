cmake_minimum_required(VERSION 3.6)
project(libuv_timer)

set(CMAKE_C_FLAGS)

link_libraries(/usr/local/Cellar/libuv/HEAD-a62f8ce/lib/libuv.a)
include_directories(/usr/local/Cellar/libuv/HEAD-a62f8ce/include)

add_executable(libuv_timer main.c /usr/local/include/node/uv.h)

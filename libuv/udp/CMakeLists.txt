cmake_minimum_required(VERSION 3.6)
project(uv_udp)

set(CMAKE_C_FLAGS)

link_libraries(/usr/local/Cellar/libuv/HEAD-9e80057/lib/libuv.a)
include_directories(/usr/local/Cellar/libuv/HEAD-9e80057/include)

# add_executable(server.out server.c /usr/local/include/node/uv.h)
# add_executable(client.out client.c /usr/local/include/node/uv.h)

add_executable(_server.out _server.c /usr/local/include/node/uv.h)
add_executable(_client.out _client.c /usr/local/include/node/uv.h)

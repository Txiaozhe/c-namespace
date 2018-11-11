cmake_minimum_required(VERSION 3.6)
project(crow_demo)

set(BOOST_ROOT $ENV{Boost_Dir})
find_package(Boost 1.66.0 COMPONENTS log thread system regex date_time REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(PROJECT_BINARY_DIR, "./build")

add_executable(crow_demo main.cpp crow_all.h)

# 目标进行链接, 目标必须已被创建
target_link_libraries(crow_demo ${Boost_LIBRARIES})

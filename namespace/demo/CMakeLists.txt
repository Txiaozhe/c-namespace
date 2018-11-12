cmake_minimum_required(VERSION 3.6)

project(namespace_demo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(ns_demo main.cpp)

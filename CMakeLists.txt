cmake_minimum_required(VERSION 3.0)
project(letsee)

set (CMAKE_CXX_STANDARD 14)
add_executable(letsee LinkedList.hpp test_LinkedList.cpp letsee.cpp)

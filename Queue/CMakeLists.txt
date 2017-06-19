cmake_minimum_required(VERSION 3.6)
project(Queue)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp Queue.cpp Queue.h)
add_executable(Queue ${SOURCE_FILES})
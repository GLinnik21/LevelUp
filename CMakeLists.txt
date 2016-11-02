cmake_minimum_required(VERSION 3.6)
project(LevelUp_3_1_0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    lvlup_3_1_0.c)

add_executable(LevelUp_3_1_0 ${SOURCE_FILES})

project(LevelUp_3_2_0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        lvlup_3_2_0.c)

add_executable(LevelUp_3_2_0 ${SOURCE_FILES})
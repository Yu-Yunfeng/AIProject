cmake_minimum_required(VERSION 3.6)
project(AIProject_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.cpp Board.h Player.cpp Player.h Grid.cpp Grid.h)
add_executable(AIProject_1 ${SOURCE_FILES})
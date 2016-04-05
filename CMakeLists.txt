cmake_minimum_required(VERSION 3.3)
project(mycommand)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  hello.c cat/cat.c cp/cp.c ls/ls.c rm/rm.c)
add_executable(mycommand ${SOURCE_FILES})
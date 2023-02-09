cmake_minimum_required(VERSION 3.23)
project(cbuffer)

set(CMAKE_C_STANDARD 99)
include_directories(include)

file(GLOB_RECURSE src src/*.c)
add_library(cbuffer ${src})

add_executable(cbuffer_test main.c)
target_link_libraries(cbuffer_test cbuffer)

cmake_minimum_required(VERSION 3.10)
project(hogevector)

set(CMAKE_CXX_STANDARD 17)

add_executable(hogevector main.cpp)
set(CMAKE_CXX_COMPILER "g++-11")

set("CMAKE_CXX_FLAGS" "-O3 -mtune=native -march=native")

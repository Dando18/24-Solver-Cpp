cmake_minimum_required(VERSION 3.8)
project(24_Solver)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Utilities.hpp)
add_executable(24_Solver ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.10)
project(pablogrep)

set(CMAKE_CXX_STANDARD 17)

add_executable(pablogrep pablogrep.cpp
        src/Grep.cpp
        src/Grep.h)
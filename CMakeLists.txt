cmake_minimum_required(VERSION 3.12)
project(inputreader)

set(CMAKE_CXX_STANDARD 14)

add_executable(inputreader main.cpp InputReader.cpp InputReader.hpp TSVInputReader.cpp TSVInputReader.hpp)
cmake_minimum_required(VERSION 3.10)
project(HTMLGenerator)

set(CMAKE_CXX_STANDARD 17)

add_library(HTMLGenerator STATIC HTMLGenerator.cpp)
target_include_directories(HTMLGenerator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

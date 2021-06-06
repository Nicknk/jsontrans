cmake_minimum_required(VERSION 3.20)

project(jsontrans
    VERSION 0.1.0
    LANGUAGES CXX)


find_package(Boost 1.75.0)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(jsontrans main.cpp)


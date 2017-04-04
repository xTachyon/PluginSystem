cmake_minimum_required(VERSION 3.6)
project(main)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(api)
add_subdirectory(myplugin)
add_subdirectory(application)
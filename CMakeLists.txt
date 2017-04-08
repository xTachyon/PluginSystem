cmake_minimum_required(VERSION 3.6)
project(pluginsystem)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(api)
add_subdirectory(myplugin)
add_subdirectory(application)

if(WIN32 OR WIN64)
  add_definitions(-DREDI_WINDOWS)
else()
  add_definitions(-DREDI_LINUX)
endif()
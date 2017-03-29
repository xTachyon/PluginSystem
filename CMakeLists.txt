cmake_minimum_required(VERSION 3.6)
project(main)

set(CMAKE_CXX_STANDARD 14)

add_library(plugin MODULE
      plugin.cxx
      plugin.hpp)

set_target_properties(plugin PROPERTIES PREFIX "")

set(SOURCE_FILES main.cxx
      api.hpp
      api.cxx
      dllkeeper.cxx
      dllkeeper.hpp)
add_executable(main ${SOURCE_FILES})
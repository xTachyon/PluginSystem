cmake_minimum_required(VERSION 3.6)
project(main)

set(CMAKE_CXX_STANDARD 14)

add_library(api STATIC
      api/api.hpp
      api/api.cxx
      api/dllkeeper.cxx
      api/dllkeeper.hpp)

add_library(plugin MODULE
      myplugin/myplugin.cxx
      myplugin/myplugin.hpp)

target_link_libraries(plugin api)
set_target_properties(plugin PROPERTIES PREFIX "")

set(SOURCE_FILES application/main.cxx
      application/server.cxx
      application/server.hpp)

add_executable(main ${SOURCE_FILES})
target_link_libraries(main api)
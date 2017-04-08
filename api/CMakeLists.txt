
add_library(api STATIC
        pluginbase.hpp
        pluginbase.cxx
        dllkeeper.cxx
        dllkeeper.hpp)

if(UNIX)
  set(options "-fPIC")
endif()

set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${options}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${options}")

set_target_properties(api PROPERTIES PREFIX "")
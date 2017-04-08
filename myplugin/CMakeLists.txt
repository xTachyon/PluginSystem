
add_library(myplugin MODULE
        myplugin.cxx
        myplugin.hpp)

if(UNIX)
  set(options "-fPIC")
endif()

set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${options}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${options}")

target_link_libraries(myplugin api)
set_target_properties(myplugin PROPERTIES PREFIX "")
add_definitions(-DEXPORTS_API)
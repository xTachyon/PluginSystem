
set(SOURCE_FILES main.cxx
        server.cxx
        server.hpp)

add_executable(pluginsystem ${SOURCE_FILES})
target_link_libraries(pluginsystem api)

if(UNIX)
  target_link_libraries(pluginsystem dl)
endif()
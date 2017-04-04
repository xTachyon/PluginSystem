
set(SOURCE_FILES main.cxx
        server.cxx
        server.hpp)

add_executable(main ${SOURCE_FILES})
target_link_libraries(main api)
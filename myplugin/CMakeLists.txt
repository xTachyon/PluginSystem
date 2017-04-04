
add_library(myplugin MODULE
        myplugin.cxx
        myplugin.hpp)

target_link_libraries(myplugin api)
set_target_properties(myplugin PROPERTIES PREFIX "")
add_definitions(-DEXPORTS_API)
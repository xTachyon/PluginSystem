
add_library(api STATIC
        pluginbase.hpp
        pluginbase.cxx
        dllkeeper.cxx
        dllkeeper.hpp)

set_target_properties(api PROPERTIES PREFIX "")
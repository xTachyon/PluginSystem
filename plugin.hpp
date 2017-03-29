#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#define EXPORTS_API

#include "api.hpp"

class MyPlugin : public Plugin {

};

extern "C" {
    void MY_API_EXPORT plugin_init(void* ptr);
    void MY_API_EXPORT plugin_term(void* ptr);
}

#endif // PLUGIN_HPP

#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#define EXPORTS_API

#include "api.hpp"

class MyPlugin : public Plugin {
  void onEnable() override;
};

extern "C" {
    void MY_API_EXPORT plugin_init(void* ptr);
}

#endif // PLUGIN_HPP

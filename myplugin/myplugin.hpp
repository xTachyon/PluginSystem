#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#define EXPORTS_API

#include "../api/pluginbase.hpp"

class MyPlugin : public Plugin {
  void onEnable() override;
};

extern "C" {
    void REDI_API_EXPORT plugin_init(void* ptr);
}

#endif // PLUGIN_HPP

#include <list>
#include "plugin.hpp"

void plugin_init(void* ptr) {
  PluginUniquePtr& plugin = *reinterpret_cast<PluginUniquePtr*>(ptr);
  
  plugin = std::make_unique<MyPlugin>();
}

void MyPlugin::onEnable() {
  Plugin::onEnable();
  std::cout << "derived class onEnable called\n";
}

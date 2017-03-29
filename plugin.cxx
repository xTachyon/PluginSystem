#include <list>
#include "plugin.hpp"

void plugin_init(void* ptr) {
  std::unique_ptr<Plugin>& plugin = *reinterpret_cast<std::unique_ptr<Plugin>*>(ptr);
  
  plugin = std::make_unique<MyPlugin>();
}

void plugin_term(void* ptr) {
  
}

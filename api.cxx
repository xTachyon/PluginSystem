#include "api.hpp"

void Server::loadPlugin(const std::string& path) {
  loadPlugin(path.c_str());
}

void Server::loadPlugin(const char* path) {
  plugins.push_back({});
  DLLKeeper& keeper = plugins.back().first;
  std::unique_ptr<Plugin>& ptr = plugins.back().second;
  
  keeper = DLLKeeper(path);
  
  if (keeper) {
    CreateFunctionPtr init = keeper.get("plugin_init");
    if (init) {
      init(reinterpret_cast<void*>(&ptr));
    }
  }
  
  if (!ptr) {
    plugins.pop_back();
  }
}

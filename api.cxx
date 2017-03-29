#include "api.hpp"

void Server::loadPlugin(const std::string& path) {
  loadPlugin(path.c_str());
}

void Server::loadPlugin(const char* path) {
  DLLKeeper keeper(path);
  std::unique_ptr<Plugin> ptr;
  
  if (keeper) {
    CreateFunctionPtr init = keeper.get("plugin_init");
    if (init) {
      init(reinterpret_cast<void*>(&ptr));
    }
  }
  
  if (ptr) {
    plugins.emplace_back(std::move(keeper), std::move(ptr));
  }
}

void Server::callOne() {
  plugins.front().second->onEnable();
}

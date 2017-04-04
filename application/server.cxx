#include "server.hpp"

Server::~Server() {
	unloadAllPlugins();
}

void Server::loadPlugin(const std::string& path) {
  loadPlugin(path.c_str());
}

void Server::loadPlugin(const char* path) {
  DLLKeeper keeper(path);
  std::unique_ptr<Plugin> plugin;
  
  if (keeper) {
    CreateFunctionPtr init = keeper.get("plugin_init");
    if (init) {
      init(reinterpret_cast<void*>(&plugin));
    }
  }

  if (plugin) {
    plugin->onEnable();
    plugins.emplace_back(std::move(keeper), std::move(plugin));
  }
}

void Server::loadPluginsFromFolder(const std::string& path) {
	loadPluginsFromFolder(path.c_str());
}

void Server::loadPluginsFromFolder(const char* path) {

}

void Server::unloadPlugin(Plugin* plugin) {
	auto end = plugins.end();
	for (auto it = plugins.begin(); it != end; ++it) {
		if (it->second.get() == plugin) {
			unloadPlugin(it);
			return;
		}
	}
}

void Server::unloadPlugin(PluginListIt it) {
	it->second->onDisable();
	plugins.erase(it);
}

void Server::unloadAllPlugins() {
	while (!plugins.empty()) {
		unloadPlugin(plugins.begin());
	}
}
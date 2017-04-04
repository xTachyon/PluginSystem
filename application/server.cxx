#include "server.hpp"

Server::~Server() {
	unloadAllPlugins();
}

PluginLoadResult Server::loadPlugin(const std::string& path) {
  return loadPlugin(path.c_str());
}

PluginLoadResult Server::loadPlugin(const char* path) {
  DLLKeeper keeper(path);
  std::unique_ptr<Plugin> plugin;
  
  if (keeper) {
    CreateFunctionPtr init = keeper.get("plugin_init");
    if (init) {
      init(reinterpret_cast<void*>(&plugin));
    } else {
      return PluginLoadResult::FunctionNotFound;
    }
  } else {
    return PluginLoadResult::InvalidLibrary;
  }

  if (plugin) {
    plugin->onEnable();
    plugins.emplace_back(std::move(keeper), std::move(plugin));
  } else {
    return PluginLoadResult::InstanceNotCreated;
  }
  
  return PluginLoadResult::Success;
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
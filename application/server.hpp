#ifndef MAIN_SERVER_HPP
#define MAIN_SERVER_HPP

#include "../api/dllkeeper.hpp"
#include "../api/pluginbase.hpp"

class Server {
public:
	using PluginList = std::list<std::pair<DLLKeeper, std::unique_ptr<Plugin>>>;
	using PluginListIt = PluginList::iterator;

	~Server();

	void loadPlugin(const std::string& path);
	void loadPlugin(const char* path);
	void loadPluginsFromFolder(const std::string& path);
	void loadPluginsFromFolder(const char* path);
	void unloadPlugin(Plugin* plugin);
	void unloadPlugin(PluginListIt it);
	void unloadAllPlugins();
  
private:
  PluginList plugins;
};

#endif //MAIN_SERVER_HPP

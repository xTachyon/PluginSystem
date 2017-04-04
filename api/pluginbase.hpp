#ifndef REDI_PLUGIN_API_HPP
#define REDI_PLUGIN_API_HPP

#include <memory>
#include <list>
#include <utility>
#include "dllkeeper.hpp"

#ifdef EXPORTS_API
#define REDI_API_EXPORT __declspec(dllexport)
#else
#define REDI_API_EXPORT __declspec(dllimport)
#endif

class Plugin {
public:
  virtual ~Plugin() = 0;

  virtual void onEnable();
	virtual void onDisable();

	bool isEnabled() const { return enabled; }

private:
	friend class Server;

	bool enabled{};
};

using PluginUniquePtr = std::unique_ptr<Plugin>;

#endif // REDI_PLUGIN_API_HPP

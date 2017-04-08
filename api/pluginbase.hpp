#ifndef REDI_PLUGIN_API_HPP
#define REDI_PLUGIN_API_HPP

#include <memory>
#include <list>
#include <utility>
#include "dllkeeper.hpp"

#if defined(_MSC_VER)
//  Microsoft
    #define REDI_EXPORT __declspec(dllexport)
    #define REDI_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//  GCC
#define REDI_EXPORT __attribute__((visibility("default")))
#define REDI_IMPORT
#else
//  do nothing and hope for the best?
    #define REDI_EXPORT
    #define REDI_IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#ifdef EXPORTS_API
#define REDI_API_EXPORT REDI_EXPORT
#else
#define REDI_API_EXPORT REDI_IMPORT
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

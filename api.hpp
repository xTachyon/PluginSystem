#ifndef API_HPP
#define API_HPP

#include <iostream>
#include <memory>
#include <list>
#include <utility>
#include "dllkeeper.hpp"

#ifdef EXPORTS_API
 #define MY_API_EXPORT __declspec (dllexport)
#else
 #define MY_API_EXPORT __declspec (dllimport)
#endif

class Plugin {
public:
  virtual ~Plugin();
  
  virtual void onEnable() {
    std::cout << "base class onEnable called\n";
  }
  
};

inline Plugin::~Plugin() {}

using PluginUniquePtr = std::unique_ptr<Plugin>;

class Server {
public:
  
  void loadPlugin(const std::string& path);
  void loadPlugin(const char* path);
  
  void callOne();
  
private:
  std::list<std::pair<DLLKeeper, std::unique_ptr<Plugin>>> plugins;
};

#endif // API_HPP

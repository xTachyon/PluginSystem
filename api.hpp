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
  
};

inline Plugin::~Plugin() {}

class Server {
public:
  
  void loadPlugin(const std::string& path);
  void loadPlugin(const char* path);
  
private:
  std::list<std::pair<DLLKeeper, std::unique_ptr<Plugin>>> plugins;
};

#endif // API_HPP

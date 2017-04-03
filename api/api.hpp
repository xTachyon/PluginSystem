#ifndef API_HPP
#define API_HPP

#include <iostream>
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
  virtual ~Plugin();
  
  virtual void onEnable();
};

inline Plugin::~Plugin() {}

using PluginUniquePtr = std::unique_ptr<Plugin>;

#endif // API_HPP

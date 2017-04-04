#include "server.hpp"

int main() {
  Server s;
  
  s.loadPlugin("E:\\repositories\\PluginSystem\\cmake-build-debug\\myplugin\\myplugin.dll");

  return 0;
}

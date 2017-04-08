#include "server.hpp"

int main() {
  Server s;
  
  s.loadPlugin("/home/andrei/redi/PluginSystem/cmake-build-debug/myplugin/myplugin.so");

  return 0;
}

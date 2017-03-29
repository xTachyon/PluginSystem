#include "api.hpp"

int main() {
  Server s;
  
  s.loadPlugin("E:\\Info\\projects\\current\\plugin\\cmake-build-debug\\plugin.dll");
  s.callOne();
  
  return 0;
}

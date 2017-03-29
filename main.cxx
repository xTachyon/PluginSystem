#include <windows.h>
#include "api.hpp"
#include "dllkeeper.hpp"

typedef void (* Ptr)(void*);

int main() {
  Server s;
  
  s.loadPlugin("E:\\Info\\projects\\current\\plugin\\cmake-build-debug\\plugin.dll");
  
  return 0;
}

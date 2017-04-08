#ifdef REDI_WINDOWS
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#include <utility>
#include "dllkeeper.hpp"

DLLKeeper::DLLKeeper() {
  dll = nullptr;
}

DLLKeeper::DLLKeeper(const char* path) {
#ifdef REDI_WINDOWS
  dll = LoadLibrary(path);
#else
  dll = dlopen(path, RTLD_LAZY);
#endif
}

DLLKeeper::DLLKeeper(DLLKeeper&& other) {
  *this = std::move(other);
}

DLLKeeper::~DLLKeeper() {
  if (dll) {
#ifdef REDI_WINDOWS
    FreeLibrary(dll);
#else
    dlclose(dll);
#endif
  }
}

CreateFunctionPtr DLLKeeper::get(const std::string& name) {
  return get(name.c_str());
}

CreateFunctionPtr DLLKeeper::get(const char* name) {
  CreateFunctionPtr ptr = nullptr;

#ifdef REDI_WINDOWS
  ptr = reinterpret_cast<CreateFunctionPtr>(GetProcAddress(dll, name));
#else
  ptr = reinterpret_cast<CreateFunctionPtr>(dlsym(dll, name));
#endif
  
  return ptr;
}

DLLKeeper& DLLKeeper::operator=(DLLKeeper&& other) {
  dll = other.dll;
  other.dll = nullptr;
  
  return *this;
}

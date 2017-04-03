#include <windows.h>
#include <utility>
#include "dllkeeper.hpp"

DLLKeeper::DLLKeeper() {
  dll = nullptr;
}

DLLKeeper::DLLKeeper(const char* path) {
  dll = LoadLibrary(path);
}

DLLKeeper::DLLKeeper(DLLKeeper&& other) {
  *this = std::move(other);
}

DLLKeeper::~DLLKeeper() {
  if (dll) {
    FreeLibrary(dll);
  }
}

CreateFunctionPtr DLLKeeper::get(const std::string& name) {
  return get(name.c_str());
}

CreateFunctionPtr DLLKeeper::get(const char* name) {
  CreateFunctionPtr ptr = nullptr;
  
  ptr = reinterpret_cast<CreateFunctionPtr>(GetProcAddress(dll, name));
  
  return ptr;
}

DLLKeeper& DLLKeeper::operator=(DLLKeeper&& other) {
  dll = other.dll;
  other.dll = nullptr;
  
  return *this;
}

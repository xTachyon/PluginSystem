#ifndef MAIN_LIBRARYKEEPER_HPP
#define MAIN_LIBRARYKEEPER_HPP

#include <string>

#ifdef REDI_WINDOWS
#ifndef _WINDEF_
class HINSTANCE__; // Forward or never
typedef HINSTANCE__* HINSTANCE;
#endif
#else

#endif

using CreateFunctionPtr = void (*)(void*);

class DLLKeeper {
public:
  DLLKeeper();
  DLLKeeper(const char* path);
  DLLKeeper(const DLLKeeper&) = delete;
  DLLKeeper(DLLKeeper&& other);
  ~DLLKeeper();
  
  DLLKeeper& operator=(const DLLKeeper&) = delete;
  DLLKeeper& operator=(DLLKeeper&& other);
  
  operator bool() const { return static_cast<bool>(dll); }
  
  CreateFunctionPtr get(const std::string& name);
  CreateFunctionPtr get(const char* name);
  
private:
#ifdef REDI_WINDOWS
  HINSTANCE dll;
#else
  void* dll;
#endif
};

#endif // MAIN_LIBRARYKEEPER_HPP

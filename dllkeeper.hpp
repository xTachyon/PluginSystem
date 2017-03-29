#ifndef MAIN_LIBRARYKEEPER_HPP
#define MAIN_LIBRARYKEEPER_HPP

#ifndef _WINDEF_
class HINSTANCE__; // Forward or never
typedef HINSTANCE__* HINSTANCE;
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
  
  CreateFunctionPtr get(const char* name);
  
private:
  HINSTANCE dll;
};

#endif //MAIN_LIBRARYKEEPER_HPP

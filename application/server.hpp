#ifndef MAIN_SERVER_HPP
#define MAIN_SERVER_HPP

#include "../api/dllkeeper.hpp"
#include "../api/api.hpp"

class Server {
  public:
  
  void loadPlugin(const std::string& path);
  void loadPlugin(const char* path);
  
  void callOne();
  
  private:
  std::list<std::pair<DLLKeeper, std::unique_ptr<Plugin>>> plugins;
};

#endif //MAIN_SERVER_HPP

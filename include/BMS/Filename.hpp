#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

namespace bms {
  class Filename {
  private:
    std::string path;
    std::string base;
    std::string ext;
  public:
    Filename();
    Filename(std::string string);
    std::string fullpath();
    std::string getPath();
    std::string getBase();
    std::string getExt();
    void setPath(std::string path_);
    void setBase(std::string base_);
    void setExt(std::string ext_);
    bool test();
  };
}

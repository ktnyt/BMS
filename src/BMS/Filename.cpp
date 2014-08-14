#include "BMS/Filename.hpp"

namespace bms {
  Filename::Filename() {
    path = "";
    base = "";
    ext = "";
  }

  Filename::Filename(std::string string) {
    std::string ppath = "(.*)/(.+)";
    std::string pbase = "(.+)\\.(.+)";

    std::regex rpath;
    std::regex rbase;

    std::smatch m;

    std::string file;

    path = "";
    base = "";
    ext = "";

    {
      using namespace std::regex_constants;
      rpath = std::regex(ppath, extended | optimize | collate);
      rbase = std::regex(pbase, extended | optimize | collate);
    }

    if(std::regex_match(string, m, rpath)) {
      path = m[1].str();
      file = m[2].str();
    } else {
      file = string;
    }

    if(std::regex_match(file, m, rbase)) {
      base = m[1].str();
      ext = m[2].str();
    } else {
      base = file;
    }
  }

  std::string Filename::fullpath() {
    std::string fullpath = "";

    if(path.length()) {
      fullpath += path + "/";
    }

    fullpath += base;

    if(ext.length()) {
      fullpath += "." + ext;
    }

    return fullpath;
  }

  std::string Filename::getPath() {
    return path;
  }

  std::string Filename::getBase() {
    return base;
  }

  std::string Filename::getExt() {
    return ext;
  }

  void Filename::setPath(std::string path_) {
    path = path_;
  }

  void Filename::setBase(std::string base_) {
    base = base_;
  }

  void Filename::setExt(std::string ext_) {
    ext = ext_;
  }

  bool Filename::test() {
    std::ifstream test(fullpath());
    return test.good();
  }
}

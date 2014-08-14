#include "gtest/gtest.h"

#include "BMS/Filename.hpp"

#include <iostream>
#include <string>

class FilenameChangepath : public ::testing::Test {
protected:
  bms::Filename filename;
  std::string initpath;
  std::string fullpath;
  std::string init;
  std::string path;
  std::string base;
  std::string ext;

  FilenameChangepath() {
    init = "/path/to/somewhere";
    path = "/path/to/elsewhere";
    base = "base";
    ext = "ext";
    fullpath = path + "/" + base + "." + ext;
    initpath = init + "/" + base + "." + ext;
    filename = bms::Filename(initpath);
    filename.setPath(path);
  }
};

TEST_F(FilenameChangepath, FullpathCorrect) {
  EXPECT_TRUE(filename.fullpath() == fullpath);
}

TEST_F(FilenameChangepath, FullpathWrong) {
  EXPECT_FALSE(filename.fullpath() == std::string("random string"));
}

TEST_F(FilenameChangepath, PathCorrect) {
  EXPECT_TRUE(filename.getPath() == path);
}

TEST_F(FilenameChangepath, PathWrong) {
  EXPECT_FALSE(filename.getPath() == std::string("random string"));
}

TEST_F(FilenameChangepath, BaseCorrect) {
  EXPECT_TRUE(filename.getBase() == base);
}

TEST_F(FilenameChangepath, BaseWrong) {
  EXPECT_FALSE(filename.getBase() == std::string("random string"));
}

TEST_F(FilenameChangepath, ExtCorrect) {
  EXPECT_TRUE(filename.getExt() == ext);
}

TEST_F(FilenameChangepath, ExtWrong) {
  EXPECT_FALSE(filename.getExt() == std::string("random string"));
}

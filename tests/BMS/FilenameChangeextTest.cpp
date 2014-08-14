#include "gtest/gtest.h"

#include "BMS/Filename.hpp"

#include <iostream>
#include <string>

class FilenameChangeext : public ::testing::Test {
protected:
  bms::Filename filename;
  std::string initpath;
  std::string fullpath;
  std::string init;
  std::string path;
  std::string base;
  std::string ext;

  FilenameChangeext() {
    path = "/path/to/somewhere";
    base = "base";
    init = "ext";
    ext = "another";
    fullpath = path + "/" + base + "." + ext;
    initpath = path + "/" + base + "." + init;
    filename = bms::Filename(initpath);
    filename.setExt(ext);
  }
};

TEST_F(FilenameChangeext, FullpathCorrect) {
  EXPECT_TRUE(filename.fullpath() == fullpath);
}

TEST_F(FilenameChangeext, FullpathWrong) {
  EXPECT_FALSE(filename.fullpath() == std::string("random string"));
}

TEST_F(FilenameChangeext, PathCorrect) {
  EXPECT_TRUE(filename.getPath() == path);
}

TEST_F(FilenameChangeext, PathWrong) {
  EXPECT_FALSE(filename.getPath() == std::string("random string"));
}

TEST_F(FilenameChangeext, BaseCorrect) {
  EXPECT_TRUE(filename.getBase() == base);
}

TEST_F(FilenameChangeext, BaseWrong) {
  EXPECT_FALSE(filename.getBase() == std::string("random string"));
}

TEST_F(FilenameChangeext, ExtCorrect) {
  EXPECT_TRUE(filename.getExt() == ext);
}

TEST_F(FilenameChangeext, ExtWrong) {
  EXPECT_FALSE(filename.getExt() == std::string("random string"));
}

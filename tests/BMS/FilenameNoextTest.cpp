#include "gtest/gtest.h"

#include "BMS/Filename.hpp"

#include <iostream>
#include <string>

class FilenameNoext : public ::testing::Test {
protected:
  bms::Filename filename;
  std::string fullpath;
  std::string path;
  std::string base;
  std::string ext;

  FilenameNoext() {
    path = "/path/to/somewhere";
    base = "base";
    ext = "";
    fullpath = path + "/" + base;
    filename = bms::Filename(fullpath);
  }
};

TEST_F(FilenameNoext, FullpathCorrect) {
  EXPECT_TRUE(filename.fullpath() == fullpath);
}

TEST_F(FilenameNoext, FullpathWrong) {
  EXPECT_FALSE(filename.fullpath() == std::string("random string"));
}

TEST_F(FilenameNoext, PathCorrect) {
  EXPECT_TRUE(filename.getPath() == path);
}

TEST_F(FilenameNoext, PathWrong) {
  EXPECT_FALSE(filename.getPath() == std::string("random string"));
}

TEST_F(FilenameNoext, BaseCorrect) {
  EXPECT_TRUE(filename.getBase() == base);
}

TEST_F(FilenameNoext, BaseWrong) {
  EXPECT_FALSE(filename.getBase() == std::string("random string"));
}

TEST_F(FilenameNoext, ExtCorrect) {
  EXPECT_TRUE(filename.getExt() == ext);
}

TEST_F(FilenameNoext, ExtWrong) {
  EXPECT_FALSE(filename.getExt() == std::string("random string"));
}


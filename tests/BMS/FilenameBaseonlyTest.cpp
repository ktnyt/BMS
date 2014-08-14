#include "gtest/gtest.h"

#include "BMS/Filename.hpp"

#include <iostream>
#include <string>

class FilenameBaseonly : public ::testing::Test {
protected:
  bms::Filename filename;
  std::string fullpath;
  std::string path;
  std::string base;
  std::string ext;

  FilenameBaseonly() {
    path = "";
    base = "base";
    ext = "";
    fullpath = base;
    filename = bms::Filename(fullpath);
  }
};

TEST_F(FilenameBaseonly, FullpathCorrect) {
  EXPECT_TRUE(filename.fullpath() == fullpath);
}

TEST_F(FilenameBaseonly, FullpathWrong) {
  EXPECT_FALSE(filename.fullpath() == std::string("random string"));
}

TEST_F(FilenameBaseonly, PathCorrect) {
  EXPECT_TRUE(filename.getPath() == path);
}

TEST_F(FilenameBaseonly, PathWrong) {
  EXPECT_FALSE(filename.getPath() == std::string("random string"));
}

TEST_F(FilenameBaseonly, BaseCorrect) {
  EXPECT_TRUE(filename.getBase() == base);
}

TEST_F(FilenameBaseonly, BaseWrong) {
  EXPECT_FALSE(filename.getBase() == std::string("random string"));
}

TEST_F(FilenameBaseonly, ExtCorrect) {
  EXPECT_TRUE(filename.getExt() == ext);
}

TEST_F(FilenameBaseonly, ExtWrong) {
  EXPECT_FALSE(filename.getExt() == std::string("random string"));
}


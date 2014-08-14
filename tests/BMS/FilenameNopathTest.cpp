#include "gtest/gtest.h"

#include "BMS/Filename.hpp"

#include <iostream>
#include <string>

class FilenameNopath : public ::testing::Test {
protected:
  bms::Filename filename;
  std::string fullpath;
  std::string path;
  std::string base;
  std::string ext;

  FilenameNopath() {
    path = "";
    base = "base";
    ext = "ext";
    fullpath = base + "." + ext;
    filename = bms::Filename(fullpath);
  }
};

TEST_F(FilenameNopath, FullpathCorrect) {
  EXPECT_TRUE(filename.fullpath() == fullpath);
}

TEST_F(FilenameNopath, FullpathWrong) {
  EXPECT_FALSE(filename.fullpath() == std::string("random string"));
}

TEST_F(FilenameNopath, PathCorrect) {
  EXPECT_TRUE(filename.getPath() == path);
}

TEST_F(FilenameNopath, PathWrong) {
  EXPECT_FALSE(filename.getPath() == std::string("random string"));
}

TEST_F(FilenameNopath, BaseCorrect) {
  EXPECT_TRUE(filename.getBase() == base);
}

TEST_F(FilenameNopath, BaseWrong) {
  EXPECT_FALSE(filename.getBase() == std::string("random string"));
}

TEST_F(FilenameNopath, ExtCorrect) {
  EXPECT_TRUE(filename.getExt() == ext);
}

TEST_F(FilenameNopath, ExtWrong) {
  EXPECT_FALSE(filename.getExt() == std::string("random string"));
}


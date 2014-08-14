#include "gtest/gtest.h"

#include "BMS/Filename.hpp"

#include <iostream>
#include <string>

class FilenameRoot : public ::testing::Test {
protected:
  bms::Filename filename;
  std::string fullpath;
  std::string path;
  std::string base;
  std::string ext;

  FilenameRoot() {
    path = "/";
    base = "base";
    ext = "ext";
    fullpath = path + "/" + base + "." + ext;
    filename = bms::Filename(fullpath);
  }
};

TEST_F(FilenameRoot, FullpathCorrect) {
  EXPECT_TRUE(filename.fullpath() == fullpath);
}

TEST_F(FilenameRoot, FullpathWrong) {
  EXPECT_FALSE(filename.fullpath() == std::string("random string"));
}

TEST_F(FilenameRoot, PathCorrect) {
  EXPECT_TRUE(filename.getPath() == path);
}

TEST_F(FilenameRoot, PathWrong) {
  EXPECT_FALSE(filename.getPath() == std::string("random string"));
}

TEST_F(FilenameRoot, BaseCorrect) {
  EXPECT_TRUE(filename.getBase() == base);
}

TEST_F(FilenameRoot, BaseWrong) {
  EXPECT_FALSE(filename.getBase() == std::string("random string"));
}

TEST_F(FilenameRoot, ExtCorrect) {
  EXPECT_TRUE(filename.getExt() == ext);
}

TEST_F(FilenameRoot, ExtWrong) {
  EXPECT_FALSE(filename.getExt() == std::string("random string"));
}

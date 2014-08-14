#include "gtest/gtest.h"

#include "BMS/Filename.hpp"

#include <iostream>
#include <string>

class FilenameChangebase : public ::testing::Test {
protected:
  bms::Filename filename;
  std::string initpath;
  std::string fullpath;
  std::string init;
  std::string path;
  std::string base;
  std::string ext;

  FilenameChangebase() {
    path = "/path/to/somewhere";
    init = "base";
    base = "another";
    ext = "ext";
    fullpath = path + "/" + base + "." + ext;
    initpath = path + "/" + init + "." + ext;
    filename = bms::Filename(initpath);
    filename.setBase(base);
  }
};

TEST_F(FilenameChangebase, FullpathCorrect) {
  EXPECT_TRUE(filename.fullpath() == fullpath);
}

TEST_F(FilenameChangebase, FullpathWrong) {
  EXPECT_FALSE(filename.fullpath() == std::string("random string"));
}

TEST_F(FilenameChangebase, PathCorrect) {
  EXPECT_TRUE(filename.getPath() == path);
}

TEST_F(FilenameChangebase, PathWrong) {
  EXPECT_FALSE(filename.getPath() == std::string("random string"));
}

TEST_F(FilenameChangebase, BaseCorrect) {
  EXPECT_TRUE(filename.getBase() == base);
}

TEST_F(FilenameChangebase, BaseWrong) {
  EXPECT_FALSE(filename.getBase() == std::string("random string"));
}

TEST_F(FilenameChangebase, ExtCorrect) {
  EXPECT_TRUE(filename.getExt() == ext);
}

TEST_F(FilenameChangebase, ExtWrong) {
  EXPECT_FALSE(filename.getExt() == std::string("random string"));
}

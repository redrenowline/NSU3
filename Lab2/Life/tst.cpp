#include "gtest/gtest.h"
#include "TestCore.h"

TEST(CoreTest, tst1){
  TestCore core;
  Field fd = core.generateTwiceField();
  fd.processing();
  std::string answer = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
  std::string transp = fd.transparentField();
  EXPECT_TRUE(answer == transp);
}

TEST(CoreTest, tst2){
  TestCore core;
  Field fd = core.generateNullField();
  core.setCellAlive(fd, 2, 2);
  core.setCellAlive(fd, 1, 2);
  core.setCellAlive(fd, 3, 2);
  fd.processing();
  std::string answer = "0000000000010100000000000000000101000000000000000000000000000000000000000000000000000000000000000000";
  std::string transp = fd.transparentField();
  EXPECT_TRUE(answer == transp);
}

TEST(CoreTest, tst3){
  TestCore core;
  Field fd = core.detranspField("00000000000000111100000000000101010101001010000000100101000000100101000000001001010100010001000001001000010010100100011", 10 ,10);
  fd.processing();
  std::string answer = "0000100010000000001010110000000000101011001001000100000000011101000011110111100000000000001000001010";
  std::string transp = fd.transparentField();
  EXPECT_TRUE(answer == transp);
}

TEST(CoreTest, tst4){
  TestCore core;
  Field fd = core.detranspField("11101010000001010101010101010100000000000000101011111110100000101010101001011100000100010001111111100111001101011010100", 10 ,10);
  fd.processing();
  std::string answer = "1000000000000101000000000000000011000000000000000001101000000000000000010101000110000000010000000001";
  std::string transp = fd.transparentField();
  EXPECT_TRUE(answer == transp);
}


#include <iostream>
#include <gtest/gtest.h>

#include "BigInt.h"


TEST(basicConstructors, copy) {
	BigInt bg1(10);
	BigInt bg2 = bg1;
	EXPECT_TRUE(bg1 == bg2);
}

TEST(basicConstructors, string1) {
    BigInt bg1("140000000000000000000000");
    BigInt bg2("140000000000000000000001");
    bg2 -= bg1;
    EXPECT_TRUE(bg2 == BigInt(1));
}

TEST(basicConstructors, string2){
  BigInt bg1("-12");
  EXPECT_TRUE(bg1 == BigInt(-12));
}

TEST(basicConstructors, string3){
  bool tst = false;
  try{
    BigInt bg1("+");
  }catch(std::exception e){
    tst = true;
  }
  EXPECT_TRUE(tst);
}

TEST(basicConstructors, string4){
  bool tst = false;
  try{
    BigInt bg1("+-");
  }catch(std::exception e){
    tst = true;
  }
  EXPECT_TRUE(tst);
}

TEST(basicConstructors, string5){
  bool tst = false;
  try{
    BigInt bg1("ret");
  }catch(std::exception e){
    tst = true;
  }
  EXPECT_TRUE(tst);
}

TEST(BinOperators, plus) {
	BigInt bg1(10);
	BigInt bg2(7);
	EXPECT_TRUE(bg1 + bg2 == BigInt(17));
}

TEST(BinOperators, plus2) {
	BigInt bg1(10);
	BigInt bg2(-112);
	EXPECT_TRUE(bg1+bg2 == BigInt(10 - 112));
}

TEST(BinOperators, rel1){
  BigInt bg1("152131231231243");
  BigInt bg2("4421312311");
  EXPECT_TRUE(bg1 >= bg2);
}

TEST(BinOperators, rel2){
  BigInt bg1("152131231231243");
  BigInt bg2("4421312311");
  EXPECT_TRUE(bg1 > bg2);
}

TEST(BinOperators, div1){
  BigInt bg1("15");
  BigInt bg2("4");
  bg1 /= bg2;
  EXPECT_TRUE(bg1 == BigInt(3));
}

TEST(BinOperators, div2){
  BigInt bg1("1156");
  BigInt bg2("34");
  bg1 /= bg2;
  EXPECT_TRUE(bg1 == BigInt(1156/34));
}

TEST(BinOperators, mod1){
  BigInt bg1("1232112");
  BigInt bg2("1543");
  bg1 %= bg2;
  EXPECT_TRUE(bg1 == BigInt(1232112 % 1543));
}

TEST(BinOperators, mod2){
  BigInt bg1("-1234");
  BigInt bg2("-34");
  EXPECT_TRUE(bg1 % bg2 == BigInt((-1234) % (-34)));
}

TEST(BinOperators, minus1) {
	BigInt bg1(10);
	BigInt bg2(7);
	EXPECT_TRUE(bg1 - bg2 == BigInt(3));
}

TEST(BinOperators, minus2) {
	BigInt bg1(10);
	BigInt bg2(7);
	EXPECT_TRUE(bg2 - bg1 == BigInt(-3));
}

TEST(BinOperators, minus4){
    BigInt bg1(314);
    BigInt bg2 = bg1;
    EXPECT_TRUE(bg1 - bg2 == BigInt(0));
}

TEST(BinOperators, mult1){
    BigInt bg1(13);
    BigInt bg2(15);
    bg1 *= bg2;
    EXPECT_TRUE(bg1 == BigInt(13*15));
}

TEST(BinOperators, mult2){
  std::cout << UINT_MAX;
    BigInt bg1(INT_MAX);
    BigInt bg2(INT_MAX);
    bg1 *= bg2;
    bg1 *= bg2;
    EXPECT_TRUE(true);
}

TEST(UnOperators, plus){
    BigInt bg1(314);
    EXPECT_TRUE(+bg1 == BigInt(314));
}

TEST(UnOperators, minus){
    BigInt bg1(123456);
    EXPECT_TRUE(-bg1 == BigInt(-123456));
}

TEST(Translations, t1){
  BigInt bg("123412");
  std::string ll =  std::string(bg);
  std::string answer = "123412";
  EXPECT_TRUE(ll == answer);
}

TEST(Translations, t2){
  BigInt bg("-123412");
  std::string ll =  std::string(bg);
  std::string answer = "-123412";
  EXPECT_TRUE(ll == answer);
}

TEST(MainTests, t1){
  BigInt bg1("1232132111111");
  BigInt bg2("633232111111");
  bg1 += bg2;
  EXPECT_TRUE(std::string(bg1) == "1865364222221");
}

TEST(MainTests, t2){
  BigInt bg1("1232132111111");
  BigInt bg2("633232111111");
  bg1 -= bg2;
  EXPECT_TRUE(std::string(bg1) == "598900000000");
}

TEST(MainTests, t3){
  BigInt bg1("1232132111111");
  BigInt bg2("633232111111");
  bg2 -= bg1;
  EXPECT_TRUE(std::string(bg2) == "-598900000000");
}

TEST(MainTests, t4){
  BigInt bg1("2232132111111");
  BigInt bg2("633232111111");
  bg1 %= bg2;
  EXPECT_TRUE(std::string(bg1) == "332435777778");
}

TEST(MainTests, t5){
  BigInt bg1("2232132111111");
  BigInt bg2("633232111111");
  bg1 /= bg2;
  EXPECT_TRUE(std::string(bg1) == "3");
}

TEST(MainTests, t6){
  BigInt bg1("1231243142152131231231");
  BigInt bg2("633232111111");
  bg1 /= bg2;
  EXPECT_TRUE(std::string(bg1) == "1944378878");
}

TEST(MainTests, t7){
  BigInt bg1("7123723819721");
  BigInt bg2("633232111111");
  bg1 /= bg2;
  EXPECT_TRUE(std::string(bg1) == "11");
}

TEST(MainTests, t8){
  BigInt bg1("7123723819721");
  BigInt bg2("633232111111");
  EXPECT_TRUE(bg1 != bg2);
}

TEST(MainTests, t9){
  BigInt bg1("7123723819721");
  BigInt bg2("633232111111");
  EXPECT_FALSE(bg1 == bg2);
}

TEST(MainTests, t10){
  BigInt bg1("7142141252");
  BigInt bg2("123124124");
  bg1 = bg1 * bg1 * bg2;
  std::string strl = std::string(bg1);
  EXPECT_TRUE(std::string(bg1) == "6280583931872964369492781916");
}

TEST(MainTests, t11){
  BigInt bg1("8546654648484840");
  BigInt bg2("7878798461236458");
  BigInt bg3("7420746012508898");
  bg1 &= bg2;
  EXPECT_TRUE(bg1 == bg3);
}

TEST(MainTests, t12){
  BigInt bg1("8546654648484840");
  BigInt bg2("7878798461236458");
  BigInt bg3("9004707097212400");
  bg1 |= bg2;
  EXPECT_TRUE(bg1 == bg3);
}

TEST(MainTests, t13){
  BigInt bg1("8546654648484840");
  BigInt bg2("7878798461236458");
  BigInt bg3("1583961084703502");
  bg1 ^= bg2;
  EXPECT_TRUE(bg1 == bg3);
}

TEST(MainTests, t14){
  BigInt bg1("8546654648484840");
  BigInt bg2("18438197414766099480");
  bg1 = ~bg1;
  EXPECT_TRUE(bg1 == bg2);
}

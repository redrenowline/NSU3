
#include <iostream>
#include <gtest/gtest.h>

#include "BigInt.h"


TEST(basicConstructors, copy) {
	BigInt bg1(10);
	BigInt bg2 = bg1;
	EXPECT_TRUE(bg1 == bg2);
}

TEST(op, plus) {
	BigInt bg1(10);
	BigInt bg2(7);
	EXPECT_TRUE(bg1+bg2 == BigInt(17));
}

TEST(op, plus2) {
	BigInt bg1(10);
	BigInt bg2(-112);
	EXPECT_TRUE(bg1+bg2 == BigInt(10 - 112));
}

TEST(op, minus1) {
	BigInt bg1(10);
	BigInt bg2(7);
	EXPECT_TRUE(bg1 - bg2 == BigInt(3));
}

TEST(op, minus2) {
	BigInt bg1(10);
	BigInt bg2(7);
	EXPECT_TRUE(bg2 - bg1 == BigInt(-3));
}

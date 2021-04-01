#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

// my custom tests
TEST(EchoTest, NumString) {
	char* test_val[5];
	test_val[0] = "./c-echo";
	test_val[1] = "3";
	test_val[2] = "29";
	test_val[3] = "52";
	test_val[4] = "136";
	EXPECT_EQ("3 29 52 136", echo(5,test_val));
}

TEST(EchoTest, WithPunctuation) {
	char* test_val[4];
	test_val[0] = "./c-echo";
	test_val[1] = "hello,";
	test_val[2] = "world";
	test_val[3] = "!";
	EXPECT_EQ("hello, world !", echo(4, test_val));
}

TEST(EchoTest, Newlines) {
	char* test_val[3];
	test_val[0] = "./c-echo";
	test_val[1] = "\n";
	test_val[2] = "\n";
	EXPECT_EQ("\n \n", echo(3, test_val));
}

/*
TEST(EchoTest, Spaces) {
	char* test_val[3];
	test_val[0] = "./c-echo";
	test_val[1] = " ";
	test_val[2] = " ";
	EXPECT_EQ("   ", echo(3, test_val));
}
*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

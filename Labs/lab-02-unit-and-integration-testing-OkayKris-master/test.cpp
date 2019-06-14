#include "c-echo.h"
#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld){
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
	EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString){
	char* test_val[1]; test_val[0] = "./c-echo";
	EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, ThreeStringText){
	char* test_val[4]; test_val[0] = "./c-echo"; test_val[1] = "three"; test_val[2] = "string"; test_val[3] = "text";
	EXPECT_EQ("three string text", echo(4,test_val));
}

TEST(EchoTest, WorldHello){
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "world"; test_val[2] = "hello";
	EXPECT_EQ("world hello", echo(3,test_val));
}

TEST(EchoTest, LongText){
	char* test_val[8]; test_val[0] = "./c-echo"; test_val[1] = "I"; test_val[2] = "am"; test_val[3] = "an"; test_val[4] = "undergraduate"; test_val[5] = "computer"; test_val[6] = "science"; test_val[7] = "major";
	EXPECT_EQ("I am an undergraduate computer science major", echo(8,test_val));
}

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

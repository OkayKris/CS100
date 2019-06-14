
#include "base.hpp"
#include "gtest/gtest.h"



class SevenOpMock: public Base {
    public:
        SevenOpMock() { };
        
        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
};



TEST(OpTest, Five) {
    Op Testval(5);
    double result = 5;
    EXPECT_EQ(result, Testval.evaluate());
}

TEST(OpTest, negative) {
    Op Testval(-5);
    double result = -5;
    EXPECT_EQ(result, Testval.evaluate());
}

TEST(SubTest, SevenMock) {
    //Op T1(7);
    //Op T2(7);
    SevenOpMock testval1;
    SevenOpMock testval2;
    Sub Subtest(&testval1, &testval2);
    double result = 0;
    EXPECT_EQ(result, Subtest.evaluate());
}

TEST(OpAddTest, SevenMock) {
    Op T1(7);
    Op T2(5);
    Add Addtest(&T1, &T2);
    double result = 12;
    EXPECT_EQ(result, Addtest.evaluate());
}
TEST(OpMultTest, SevenMock) {
    Op T1(7);
    Op T2(5);
    Mult Multtest(&T1, &T2);
    double result = 35;
    EXPECT_EQ(result, Multtest.evaluate());
}
TEST(OpPowTest1, SevenMock) {
    Op T1(7);
    Op T2(5);
    Pow Powtest(&T1, &T2);
    double result = 16807;
    EXPECT_EQ(result, Powtest.evaluate());
}
TEST(OpMultTest2, SevenMock) {
    Op T1(1);
    Op T2(-1);
    Pow Powtest(&T1, &T2);
    double result = 1;
    EXPECT_EQ(result, Powtest.evaluate());
}


/*class RandMock: public Base{
  public:
    RandMock(){};
    //virtual double evaluate(){ return 
  
};*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


// int main() {
//   return 0;
// }
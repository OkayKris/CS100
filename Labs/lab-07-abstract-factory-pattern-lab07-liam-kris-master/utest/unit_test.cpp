
#include "../head/base.hpp"
#include "../head/container.hpp"
#include "../head/sort.hpp"
#include "../head/factory.hpp"
#include "../head/base_factory.hpp"
#include "gtest/gtest.h"



class SevenOpMock: public Base {
    public:
        SevenOpMock() { };
        
        virtual double evaluate() { return 7.5; }
        virtual string stringify() { return "7.5"; }
};

class MockVecContainer: public Container {
    public:
    vector<Base*> vec;
    MockVecContainer() {
        
        Op* t1 = new Op(1);
        Op* t2 = new Op(2);
        Op* t3 = new Op(3);
        vec.push_back(t1);
        vec.push_back(t2);
        vec.push_back(t3);
    }

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


TEST(VecSortB, SevenMock) {
    Op* T1 = new Op(10);
    Op* T2 = new Op(-1);
    VectorContainer Mock(new BSort);
    
    Add* Addtest = new Add(T1, T2);
    Mock.add_element(T1);
    Mock.add_element(T2);
    Mock.add_element(Addtest);
    Mock.sort();
    EXPECT_EQ(-1, Mock.at(0)->evaluate());
    EXPECT_EQ(9, Mock.at(1)->evaluate());
    EXPECT_EQ(10, Mock.at(2)->evaluate());
}

TEST(VecSortS, SevenMock) {
    Op* T1 = new Op(10);
    Op* T2 = new Op(-1);
    VectorContainer Mock(new SSort);
    
    Add* Addtest = new Add(T1, T2);
    Mock.add_element(T1);
    Mock.add_element(T2);
    Mock.add_element(Addtest);
    Mock.sort();
    EXPECT_EQ(-1, Mock.at(0)->evaluate());
    EXPECT_EQ(9, Mock.at(1)->evaluate());
    EXPECT_EQ(10, Mock.at(2)->evaluate());
}

/*class RandMock: public Base{
  public:
    RandMock(){};
    //virtual double evaluate(){ return 
  
};*/


TEST(ListSortS, SevenMock) {
    Op* T1 = new Op(10);
    Op* T2 = new Op(-1);
    ListContainer Mock(new SSort);
    
    Add* Addtest = new Add(T1, T2);
    Mock.add_element(T1);
    Mock.add_element(T2);
    Mock.add_element(Addtest);
    Mock.sort();
    EXPECT_EQ(-1, Mock.at(0)->evaluate());
    EXPECT_EQ(9, Mock.at(1)->evaluate());
    EXPECT_EQ(10, Mock.at(2)->evaluate());
}

TEST(ListSortB, SevenMock) {
    Op* T1 = new Op(10);
    Op* T2 = new Op(-1);
    ListContainer Mock(new SSort);
    
    Add* Addtest = new Add(T1, T2);
    Mock.add_element(T1);
    Mock.add_element(T2);
    Mock.add_element(Addtest);
    Mock.sort();
    EXPECT_EQ(-1, Mock.at(0)->evaluate());
    EXPECT_EQ(9, Mock.at(1)->evaluate());
    EXPECT_EQ(10, Mock.at(2)->evaluate());
}



TEST(CEIL, T1) {
    Op* T1 = new Op(10.5);
    Op* T2 = new Op(-1);
    
    Base* test = new Ceil(T1);
    EXPECT_EQ(11, test->evaluate());

}

TEST(FLOOR, T1) {
    Op* T1 = new Op(10.5);
    Op* T2 = new Op(-1);
    
    Base* test = new Floor(T1);
    EXPECT_EQ(10, test->evaluate());

}

TEST(ABS, T1) {
    Op* T1 = new Op(10.5);
    Op* T2 = new Op(-1);
    
    Base* test = new Abs(T2);
    EXPECT_EQ(1, test->evaluate());

}

TEST(Trunc, T1) {
    Op* T1 = new Op(10.5);
    Op* T2 = new Op(-1);
    
    Base* Addd = new Add(T1,T2);
    
    Base* test = new Trunc(Addd);
    EXPECT_EQ(9.5, test->evaluate());

}

TEST(doubleFac, T1) {
    BaseFactory* Factory = new doubleFac;
    Base* test = Factory->createOp(1234567.89);
    EXPECT_EQ("1234567.890000", test->stringify());

}

TEST(precFac, T1) {
    BaseFactory* Factory = new precFac;
    Base* test = Factory->createOp(1234567.8911);
    EXPECT_EQ("1234567.891", test->stringify());
}

TEST(sciFac, T1){
    BaseFactory* Fac = new sciFac;
    Base* test = Fac->createOp(6789898989.33999443);
    EXPECT_EQ("6.7899e+09", test->stringify());
}

TEST(precisionOp, T1) {
    Base* test = new PrecisionOp(1234567.89);
    EXPECT_EQ("1234567.890", test->stringify());
}

TEST(SciOp, T1) {
    Base* test = new SciOp(1234567.89);
    EXPECT_EQ("1.23457e+06", test->stringify());
}

TEST(precisionRand, T1) {
    Base* test = new PrecisionRand();
    EXPECT_EQ("83.000", test->stringify());
}

TEST(sciRand, T1) {
    Base* test = new SciRand;
    EXPECT_EQ("83", test->stringify());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


// int main() {
//   return 0;
// }

#include "../head/base.hpp"

#include "../head/Iterator.hpp"
#include "../head/visitor.hpp"
#include "../head/operators.hpp"
#include "gtest/gtest.h"




TEST(NullIterator, T1){
    Op* op1 = new Op(1);
    
    Iterator* test= new NullIterator(op1);
    
    
    EXPECT_EQ(test->current(), nullptr);
}

TEST(UnIterator, T1){
    Base* op1 = new Op(1);
    Base* ab1 = new Abs(op1);
    Iterator* test= new UnaryIterator(ab1);
    test->first();
    
    EXPECT_EQ(test->current()->evaluate(), 1);
}

TEST(BinIterator, T1){
    Base* op1 = new Op(1);
    Base* op2 = new Op(2);
    Base* ad1 = new Add(op1, op2);
    Iterator* test= new BinaryIterator(ad1);
    test->first();
    test->next();
    
    EXPECT_EQ(test->current()->evaluate(), 1);
    EXPECT_EQ(test->is_done(), false);
}

TEST(PreIterator, T1){
    Op* op1 = new Op(1);
    Op* op2 = new Op(2);
    Op* op3 = new Op(3);
    Op* op4 = new Op(4);
    Op* op5 = new Op(6);
    
    Add* add = new Add(op1, op2);
    Mult* mul1 = new Mult(add, op3);
    Mult* mul2 = new Mult(mul1, op4);
    Div* div1 = new Div(mul2, op5);
    
    PreorderIterator* tester = new PreorderIterator(div1);
    tester->first();
    tester->next();
    
    //EXPECT_EQ("1", tester->first()->stringify());
    EXPECT_EQ(tester->current()->evaluate(), 9);
}

TEST(Visitor, T1){
    Op* op1 = new Op(1);
    Op* op2 = new Op(2);
    Op* op3 = new Op(3);
    Op* op4 = new Op(4);
    Op* op5 = new Op(6);
    
    Add* add = new Add(op1, op2);
    Mult* mul1 = new Mult(add, op3);
    Mult* mul2 = new Mult(mul1, op4);
    Div* div1 = new Div(mul2, op5);
    Base* Dummy = new Abs(div1);
    
    PreorderIterator* it = new PreorderIterator(Dummy);
    CountVisitor* v = new CountVisitor;
    for(it->first(); !it->is_done(); it->next()) {
      it->current()->accept(v);
    }
    
    EXPECT_EQ(v->op_count(), 5);
    EXPECT_EQ(v->add_count(), 1);
    EXPECT_EQ(v->div_count(), 1);
    EXPECT_EQ(v->mult_count(), 2);
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}




// int main() {
//   return 0;
// }
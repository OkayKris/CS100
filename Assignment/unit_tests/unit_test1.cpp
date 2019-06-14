#include "gtest/gtest.h"
#include "../header/connector.hpp"
#include "../header/OrConnector.hpp"
#include "../header/AndConnector.hpp"
#include "../header/commandinput.hpp"


struct MockConnector : public Connector {
    string command;
    MockConnector(string input) :command(input){}
};

TEST(MACTest, MockConnector){
    Connector* t1 = new Connector;
    t1->set_cmd("echo A && echo B");
    t1->execute();
    
    EXPECT_EQ(true, t1->passing());
}

TEST(MOCTest, MockConnector){
    Connector* t1 = new Connector;
    t1->set_cmd("bleh || echo A");
    t1->execute();
    
    EXPECT_EQ(false, t1->passing());
}

TEST(MACTest2, MockConnector){
    Connector* t1 = new Connector;
    t1->set_cmd("jidajsdiaji && echo A");    
    t1->execute();
    
    EXPECT_EQ(false, t1->passing());
}

TEST(PrecTest1, t1){
  Connector* t1 = new Connector;
  t1->set_cmd("(echo A && echo B) && (echo C && echo D)");
  t1->execute();
  
  EXPECT_EQ(false, t1->passing());
}

TEST(ConnTest2, MockConnector){
  Connector* t1 = new Connector;
  t1->set_cmd("echo a || echo b");
  t1->execute();
  EXPECT_EQ(true, t1->passing());
}

TEST(PipeTest1, T1){
  Connector *t1 = new Connector;
  t1->set_cmd("ls -a | grep Make");
  t1->execute();
  EXPECT_EQ(true, t1->passing());
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
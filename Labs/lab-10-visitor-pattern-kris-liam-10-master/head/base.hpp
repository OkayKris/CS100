#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string.h>
#include <string>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
//#include "visitor.hpp"
//#include "Iterator.hpp"



using namespace std;
class Iterator;
class CountVisitor;



class Base {
    public:
        /* Constructors */
        Base() {}
        virtual Base* get_left();
        virtual Base* get_right();
        virtual Iterator* create_iterator();
        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual string stringify() = 0;
        virtual void accept(CountVisitor* v) = 0;
};

class Op: public Base {
    protected:
        double value;
    public:
        Op();
        Op(double v);
        virtual double evaluate();
        virtual string stringify();
        void accept(CountVisitor* v);
};

class Rand: public Base {
  
  protected:
    double value;
    
  public:

    Rand();
  
    virtual double evaluate();
    virtual string stringify();
    void accept(CountVisitor* v);
};

class PrecisionRand : public Rand {
  public:
    PrecisionRand();
    virtual string stringify();

};

class SciRand : public Rand {
  public:
    SciRand();
    virtual string stringify();
};

class PrecisionOp : public Op {
  public:
    PrecisionOp(double v);
    virtual string stringify();
};

class SciOp : public Op {
  public:
    SciOp(double v);
    virtual string stringify();
};

#endif //__BASE_HPP__

    //BaseFactory* Factory = new precFac;
    //Base* test = Factory->createOp(1456.78);
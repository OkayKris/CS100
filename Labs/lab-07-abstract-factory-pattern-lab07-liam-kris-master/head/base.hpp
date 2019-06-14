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

using namespace std;

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual string stringify() = 0;
};

class Op: public Base {
  protected:
    double value;
  public:
    Op() {}
    Op(double v){
      value = v;
    }
    virtual double evaluate(){ return value; }
    virtual string stringify(){ return to_string(value) ; }
      
};

class Rand: public Base {
  
  protected:
    double value;
    
  public:

    Rand(){
      srand(1);
      value = rand() % 100;
    }
  
    virtual double evaluate(){ return value; }
    virtual string stringify(){ return to_string(value); }
};

class PrecisionRand : public Rand {
  public:
    PrecisionRand(){
      srand(1);
     value = rand() % 100;
    }
    virtual string stringify(){
      stringstream ss;
      ss << fixed;
      ss << std::setprecision(3);
      ss << value;
      return ss.str();
    }
};


class SciRand : public Rand {
  public:
    SciRand(){
     srand(1);
     value = rand() % 100;
    }
    virtual string stringify(){
      ostringstream sciObj;
      sciObj << value;
      return sciObj.str();
    }
};

class PrecisionOp : public Op {
  public:
    PrecisionOp(double v){
      value = v;
    }
    virtual string stringify(){
      stringstream ss;
      ss << fixed << std::setprecision(3);
      ss << value;
      return ss.str();
    }
};


class SciOp : public Op {
  public:
    SciOp(double v){
      value = v;
    }
    virtual string stringify(){
      ostringstream sciObj;
      sciObj << value;
      return sciObj.str();
    }
};


#endif //__BASE_HPP__

    //BaseFactory* Factory = new precFac;
    //Base* test = Factory->createOp(1456.78);
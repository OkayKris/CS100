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
  private:
    double value;
  public:
    Op(double v){
      value = v;
    }
    double evaluate(){ return value; }
    string stringify(){ return to_string(value) ; }
      
};

class Rand: public Base {
  
  private:
    double value;
    
  public:
    Rand(){
      srand(1);
      value = rand() % 100;
    }
  
    double evaluate(){ return value; }
    string stringify(){ return to_string(value); }
};


#endif //__BASE_HPP__
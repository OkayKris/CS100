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

class Mult: public Base {
  protected:
    Base* lhs;
    Base* rhs;
  public:
    Mult(Base* lhs, Base* rhs){
      this->lhs = lhs;
      this->rhs = rhs;
    }
    double evaluate(){
      return lhs->evaluate() * rhs->evaluate(); 
    }
    string stringify(){
            return "(" + lhs->stringify() + " * " + rhs->stringify() + ")";
        }
};

class Div: public Base{
  protected:
    Base* lhs;
    Base* rhs;
  public:
    Div(Base* lhs, Base* rhs){
      this->lhs = lhs;
      this->rhs = rhs;
    }
    double evaluate(){
        return lhs->evaluate()/rhs->evaluate();
    }
    string stringify(){
            return "(" + lhs->stringify() + " / " + rhs->stringify() + ")";
        }
};

class Add: public Base{
  protected:
    Base* lhs;
    Base* rhs;
  public:
    Add(Base* lhs, Base* rhs){
      this->lhs = lhs;
      this->rhs = rhs;
    }
    double evaluate(){
        return lhs->evaluate() + rhs->evaluate();   
    }
    string stringify(){
            return "(" + lhs->stringify() + " + " + rhs->stringify() + ")";
        }
};

class Sub: public Base{
    protected:
        Base* lhs;
        Base* rhs;
    public:
        Sub(Base* lhs, Base* rhs){
            this->lhs = lhs;
            this->rhs = rhs;
        }
        double evaluate(){
            return lhs->evaluate() - rhs->evaluate();
        }
        string stringify(){
            return "(" + lhs->stringify() + " - " + rhs->stringify() + ")";
        }
};

class Pow: public Base{
    protected:
      Base* lhs; 
      Base* rhs;
      
    public:
      Pow(Base* lhs, Base* rhs){
          this->lhs = lhs;
          this->rhs = rhs;
      }
      double evaluate() {
        return pow(lhs->evaluate(), rhs->evaluate());
      }
      string stringify() {
        return "(" + lhs->stringify() + " ** " + rhs->stringify() + ")"; 
      }
};



#endif //__BASE_HPP__
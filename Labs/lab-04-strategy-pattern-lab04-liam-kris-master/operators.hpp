#ifndef __OPERATOR_HPP__
#define __OPERATOR_HPP__

#include "base.hpp"

using namespace std;

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

#endif // __OPERATORS_HPP__
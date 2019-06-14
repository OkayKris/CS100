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
            return lhs->stringify() + " * " + rhs->stringify();
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
            return lhs->stringify() + " / " + rhs->stringify();
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
            return lhs->stringify() + " + " + rhs->stringify();
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
            return lhs->stringify() + " - " + rhs->stringify();
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
        return lhs->stringify() + " ** " + rhs->stringify(); 
      }
};

class Decor: public Base{
    protected:
    Base* root;
    public:
    Decor() {}
      virtual double evaluate() {
        return root->evaluate();
      }
      
      virtual string stringify() {
        return root->stringify(); 
      }
};

class Ceil : public Decor {
  public:
    Ceil(Base* rot) {
      this->root = rot;
    }
  virtual double evaluate() {
    return ceil(root->evaluate());
  }
};

class Floor : public Decor {
  public:
    Floor(Base* rot) {
      this->root = rot;
    }
  virtual double evaluate() {
    return floor(root->evaluate());
  }
};

class Abs : public Decor {
  public:
    Abs(Base* rot) {
      this->root = rot;
    }
  virtual double evaluate() {
    return abs(root->evaluate());
  }
};

class Paren : public Decor {
  public:
    Paren(Base* rot) {
      this->root = rot;
    }
  virtual string stringify() {
    return "(" + root->stringify() + ")";
  }
};

class Trunc : public Decor {
  public:
    Trunc(Base* rot) {
      this->root = rot;
    }
  virtual string stringify() {
    return to_string(root->evaluate());
  }
};


#endif // __OPERATORS_HPP__
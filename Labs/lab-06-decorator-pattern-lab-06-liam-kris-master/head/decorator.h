#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include "base.hpp"

class baseDecorator : public Base {
  protected:
    Base* root;
  public:
    
    virtual double evaluate() {return root->evaluate();}
    virtual string stringify() {return root->stringify();}
};

class Trunc : public baseDecorator {
  public: 
  Trunc() {}
  Trunc(Base* feed) {this->root = feed;}
  virtual string stringify() {
    return to_string(root->evaluate());
  }
};

class Paren : public baseDecorator {
  public:
  Paren(Base* feed) {this->root = feed;}
  virtual string stringify() {
    return ("(" + root->stringify() + ")");
  }
 
};

class Ceil : public baseDecorator {
    public:
        Ceil(Base *feed){ this->root = feed;}
        double evaluate(){ return ceil(root->evaluate());}
};

class Floor : public baseDecorator {
    public:
        Floor(Base *feed){this->root = feed;}
        double evaluate(){return floor(root->evaluate());}
};

class Abs : public baseDecorator {
    public:
        Abs(Base *feed){this->root = feed;}
        double evaluate(){return abs(root->evaluate());}
};

#ifndef __OPERATOR_HPP__
#define __OPERATOR_HPP__

#include "base.hpp"


using namespace std;
class Iterator;


class Mult: public Base {
  protected:
    Base* lhs;
    Base* rhs;
  public:
    Mult(Base* lhs, Base* rhs);
    double evaluate();
    string stringify();
    virtual Base* get_left() ;
    virtual Base* get_right() ;
    virtual Iterator* create_iterator() ;
};

class Div: public Base {
  protected:
    Base* lhs;
    Base* rhs;
  public:
    Div(Base* lhs, Base* rhs);
    double evaluate();
    string stringify();
    virtual Base* get_left();
    virtual Base* get_right();
    virtual Iterator* create_iterator();
};

class Add: public Base {
  protected:
    Base* lhs;
    Base* rhs;
  public:
    Add(Base* lhs, Base* rhs);
    double evaluate();
    string stringify();
    virtual Base* get_left();
    virtual Base* get_right();
    virtual Iterator* create_iterator();
};

class Sub: public Base {
  protected:
    Base* lhs;
    Base* rhs;
  public:
    Sub(Base* lhs, Base* rhs);
    double evaluate();
    string stringify();
    virtual Base* get_left();
    virtual Base* get_right();
    virtual Iterator* create_iterator();
};

class Pow: public Base {
  protected:
    Base* lhs;
    Base* rhs;
  public:
    Pow(Base* lhs, Base* rhs);
    double evaluate();
    string stringify();
    virtual Base* get_left() ;
    virtual Base* get_right() ;
    virtual Iterator* create_iterator();
};

class Decor: public Base{
    protected:
    Base* root;
    public:
    Decor();
      virtual double evaluate();
      
      virtual string stringify();
    virtual Base* get_left() ;
    virtual Base* get_right() ;
    virtual Iterator* create_iterator();
};

class Ceil : public Decor {
  public:
    Ceil(Base* rot) ;
  virtual double evaluate() ;
};

class Floor : public Decor {
  public:
    Floor(Base* rot) ;
  virtual double evaluate() ;
};

class Abs : public Decor {
  public:
    Abs(Base* rot) ;
  virtual double evaluate() ;
};

class Paren : public Decor {
  public:
    Paren(Base* rot) ;
  virtual string stringify() ;
};

class Trunc : public Decor {
  public:
    Trunc(Base* rot) ;
  virtual string stringify() ;
};

#endif // __OPERATORS_HPP__
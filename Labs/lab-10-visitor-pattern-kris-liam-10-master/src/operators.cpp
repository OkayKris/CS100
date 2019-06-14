#include "../head/operators.hpp"
#include "../head/base.hpp"
#include "../head/Iterator.hpp"
#include "../head/visitor.hpp"

using namespace std;


Mult::Mult(Base* lhs, Base* rhs){
  this->lhs = lhs;
  this->rhs = rhs;
}

double Mult::evaluate(){
  return lhs->evaluate() * rhs->evaluate(); 
}

string Mult::stringify(){
        return lhs->stringify() + " * " + rhs->stringify();
    }
    
 Base* Mult::get_left() { return lhs; }
 Base* Mult::get_right() { return rhs; }
 Iterator* Mult::create_iterator() {return new BinaryIterator(this);}
 


Div::Div(Base* lhs, Base* rhs){
    this->lhs = lhs;
    this->rhs = rhs;
}

double Div::evaluate(){
    return lhs->evaluate()/rhs->evaluate();
}

string Div::stringify(){
    return lhs->stringify() + " / " + rhs->stringify();
}

 Base* Div::get_left() { return lhs; }
 Base* Div::get_right() { return rhs; }
 Iterator* Div::create_iterator() {return new BinaryIterator(this);}
Add::Add(Base* lhs, Base* rhs){
    this->lhs = lhs;
    this->rhs = rhs;
}

double Add::evaluate(){
    return lhs->evaluate() + rhs->evaluate();   
}

string Add::stringify(){
    return lhs->stringify() + " + " + rhs->stringify();
}
    
 Base* Add::get_left() { return lhs; }
 Base* Add::get_right() { return rhs; }
 Iterator* Add::create_iterator() {return new BinaryIterator(this);}

Sub::Sub(Base* lhs, Base* rhs){
    this->lhs = lhs;
    this->rhs = rhs;
}

double Sub::evaluate(){
    return lhs->evaluate() - rhs->evaluate();
}

string Sub::stringify(){
    return lhs->stringify() + " - " + rhs->stringify();
}

 Base* Sub::get_left() { return lhs; }
 Base* Sub::get_right() { return rhs; }
 Iterator* Sub::create_iterator() {return new BinaryIterator(this);}

Pow::Pow(Base* lhs, Base* rhs){
    this->lhs = lhs;
    this->rhs = rhs;
}

double Pow::evaluate() {
    return pow(lhs->evaluate(), rhs->evaluate());
}
string Pow::stringify() {
    return lhs->stringify() + " ** " + rhs->stringify(); 
}

 Base* Pow::get_left() { return lhs; }
 Base* Pow::get_right() { return rhs; }
 Iterator* Pow::create_iterator() {return new BinaryIterator(this);}

Decor::Decor() {}
 double Decor::evaluate() {
    return root->evaluate();
}

string Decor::stringify() {
    return root->stringify(); 
}

 Base* Decor::get_left() { return root; }
 Base* Decor::get_right() { return nullptr; }
 Iterator* Decor::create_iterator() {return new UnaryIterator(this);}

Ceil::Ceil(Base* rot) {
    this->root = rot;
}
 double Ceil::evaluate() {
    return ceil(root->evaluate());
}

Floor::Floor(Base* rot) {
    this->root = rot;
}

 double Floor::evaluate() {
    return floor(root->evaluate());
}

Abs::Abs(Base* rot) {
    this->root = rot;
}
 double Abs::evaluate() {
    return abs(root->evaluate());
}

Paren::Paren(Base* rot) {
    this->root = rot;
}
 string Paren::stringify() {
    return "(" + root->stringify() + ")";
}

Trunc::Trunc(Base* rot) {
    this->root = rot;
}
 string Trunc::stringify() {
    return to_string(root->evaluate());
}

void Op::accept(CountVisitor* v) {v->visit_op();}
void Rand::accept(CountVisitor* v){ v->visit_rand();}
void Mult::accept(CountVisitor* v){ v->visit_mult();}
void Div::accept(CountVisitor* v) {v->visit_div();}
void Add::accept(CountVisitor* v) {v->visit_add();}
void Sub::accept(CountVisitor* v) {v->visit_sub();}
void Pow::accept(CountVisitor* v) {v->visit_pow();}

void Ceil::accept(CountVisitor* v) {v->visit_ceil();}
void Floor::accept(CountVisitor* v) {v->visit_floor();}
void Abs::accept(CountVisitor* v){ v->visit_abs();}
void Trunc::accept(CountVisitor* v) {v->visit_trunc();}
void Paren::accept(CountVisitor* v) {v->visit_paren();}
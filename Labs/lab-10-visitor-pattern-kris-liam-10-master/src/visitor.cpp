#include "../head/visitor.hpp"
#include "../head/base.hpp"
#include "../head/operators.hpp"

CountVisitor::CountVisitor() {
    ops = 0;
    rands = 0;
    mults = 0;
    divs = 0;
    add = 0;
    sub = 0;
    pow = 0;
    ceil = 0;
    floor = 0;
    abs = 0;
    trunc = 0;
    paren = 0;
}

void CountVisitor::visit_op() {++ops;}
void CountVisitor::visit_rand() {++rands;}
void CountVisitor::visit_mult() {++mults;}
void CountVisitor::visit_div() {++divs;}
void CountVisitor::visit_add() {++add;}
void CountVisitor::visit_sub() {++sub;}
void CountVisitor::visit_pow() {++pow;}
void CountVisitor::visit_ceil() {++ceil;}
void CountVisitor::visit_floor() {++floor;}
void CountVisitor::visit_abs() {++abs;}
void CountVisitor::visit_trunc() {++trunc;}
void CountVisitor::visit_paren() {++paren;}

int CountVisitor::op_count() {return ops;}
int CountVisitor::rand_count() {return rands;}
int CountVisitor::mult_count() {return mults;}
int CountVisitor::div_count() {return divs;}
int CountVisitor::add_count() {return add;}
int CountVisitor::sub_count() {return sub;}
int CountVisitor::pow_count() {return pow;}
int CountVisitor::ceil_count() {return ceil;}
int CountVisitor::floor_count() {return floor;}
int CountVisitor::abs_count() {return abs;}
int CountVisitor::trunc_count() {return trunc;}
int CountVisitor::paren_count() {return paren;}
#include "../head/base.hpp"
#include "../head/Iterator.hpp"
#include "../head/visitor.hpp"
using namespace std;


 Base* Base::get_left() { return nullptr; }
 Base* Base::get_right() { return nullptr; }
 Iterator* Base::create_iterator() {return new NullIterator(this);}

Op::Op() {}
Op::Op(double v){
    value = v;
}

 double Op::evaluate(){ return value; }
 string Op::stringify(){ return to_string(value) ; }


Rand::Rand(){
    srand(1);
    value = rand() % 100;
}
  
 double Rand::evaluate(){ return value; }
 string Rand::stringify(){ return to_string(value); }

PrecisionRand::PrecisionRand(){
    srand(1);
    value = rand() % 100;
}

 string PrecisionRand::stringify(){
    stringstream ss;
    ss << fixed;
    ss << std::setprecision(3);
    ss << value;
    return ss.str();
}

SciRand::SciRand(){
    srand(1);
    value = rand() % 100;
}

 string SciRand::stringify(){
    ostringstream sciObj;
    sciObj << value;
    return sciObj.str();
}

PrecisionOp::PrecisionOp(double v){
    value = v;
}

 string PrecisionOp::stringify(){
    stringstream ss;
    ss << fixed << std::setprecision(3);
    ss << value;
    return ss.str();
}

SciOp::SciOp(double v){
    value = v;
}

 string SciOp::stringify(){
    ostringstream sciObj;
    sciObj << value;
    return sciObj.str();
}

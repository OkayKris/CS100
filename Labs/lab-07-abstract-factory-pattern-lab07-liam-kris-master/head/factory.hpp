#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include "base_factory.hpp"



class doubleFac : public BaseFactory {
    private:
        double value;
    public:
        doubleFac() {}
        doubleFac(double v) : value(v){};
        Op* createOp(double value){
            return new Op(value);
        }
        Rand* createRand(){
            return new Rand();
        }
};

class precFac : public BaseFactory {
    private:
        double value;
    public:
        precFac() {}
        precFac(double v) : value(v) {};
        Op* createOp(double value){
            return new PrecisionOp(value);
        }
        Rand* createRand(){
            return new PrecisionRand();
        }
};

class sciFac : public BaseFactory{
    private:
        double value;
    public:
        sciFac(){}
        sciFac(double v) : value(v) {};
        Op* createOp(double value){
            return new SciOp(value);
        }
        Rand* createRand(){
            return new SciRand();
        }
};

#endif
#ifndef __BASE_FACTORY_HPP__
#define __BASE_FACTORY_HPP__

#include "base.hpp"

class BaseFactory {
    public:
        /* Constructor */
        BaseFactory() {}
        virtual Base* createOp(double value){
            return new Op(value);
        }
        virtual Rand* createRand(){
            return new Rand();
        }
};
class doubleFac : public BaseFactory {
    private:
        double value;
    public:
        doubleFac() {}
        doubleFac(double v) : value(v){};
        Base* createOp(double value){
            return new Op(value);
        }
        Rand* createRand(){
            return new Rand();
        }
};

class PrecisionFactory : public BaseFactory {
    private:
        double value;
    public:
        PrecisionFactory() {}
        PrecisionFactory(double v) : value(v) {};
        Base* createOp(double value){
            return new PrecisionOp(value);
        }
        Rand* createRand(){
            return new PrecisionRand();
        }
};

class SciFactory : public BaseFactory{
    private:
        double value;
    public:
        SciFactory(){}
        SciFactory(double v) : value(v) {};
        Base* createOp(double value){
            return new SciOp(value);
        }
        Rand* createRand(){
            return new SciRand();
        }
};
#endif //__BASE_FACTORY_HPP__

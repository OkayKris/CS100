#include <string.h>
#include <string>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>


#include "../head/base.hpp"
#include "../head/operators.hpp"
#include "../head/Iterator.hpp"
#include "../head/visitor.hpp"



using namespace std;




int main() { //Does operation (2 - 4)^(0.5*4) // This equals 4.
    Op* T1 = new Op(1);
    Op* T2 = new Op(2);
    Op* T3 = new Op(3);
    Op* T4 = new Op(4);
    Op* T5 = new Op(5);
    Op* T6 = new Op(6);

    //BaseFactory* Factory = new sciFac;
    Base* test = new SciRand;
    //Base* test = new PrecisionOp(1267788787.1234);
    //cout << test->stringify();
    Base* t = new Add(T1, T2);
    Base* t1 = new Add(T3, T4);
    Base* t2 = new Add(T5, T6);
    
    Base* t3 = new Add(t, t1);
    
    
    
    Base* t5 = new Abs(t3);
    Base* t4 = new Add(t5,t2);
    Base* t6 = new Abs(t4);
    // Iterator* i = t->create_iterator();
    // i->first();

    // while(!i->is_done()) {
    //     cout << i->current()->stringify() << endl;
    //     i->next();
    // }
    //  cout << t->stringify() << endl;
    Iterator* it = new PreorderIterator(t6);
    CountVisitor* v = new CountVisitor;
    //cout << t6->stringify() << endl;
    
    for(it->first(); !it->is_done(); it->next()){
        Base* temp = it->current();
        temp->accept(v);
        cout << temp->stringify() << endl;
    }
    cout << "Ops: " << v->op_count() << " Add: " << v->add_count() << " Abs: " << v->abs_count() <<  endl;
    
    return 0;
}
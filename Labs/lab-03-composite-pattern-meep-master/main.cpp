#include <string.h>
#include <string>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "base.hpp"

using namespace std;


int main() { //Does operation (2 - 4)^(0.5*4) // This equals 4.
    Op O1(2.0); // will first stringify, then evaluate and display.
    Op O2(4.0);
    Op O3(0.5);
    Op O4(4.0);
    Rand T1;
    string randPrint;
    string print;
    
    randPrint = T1.stringify();
    cout << "Rand stringify test: " << randPrint << endl;
    
    Op* p1 = &O1;
    Sub subtract(&O1, &O2);
    Mult multiply(&O4,&O3);
    
    Pow test(&subtract,&multiply);
    
    print = test.stringify() + " = " + to_string(test.evaluate());
    cout << "Expression Tree output:" << endl << print << endl;
    
    
    return 0;
}
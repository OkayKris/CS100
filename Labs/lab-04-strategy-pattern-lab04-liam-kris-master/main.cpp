#include <string.h>
#include <string>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "base.hpp"
#include "operators.hpp"
#include "sort.hpp"
#include "container.hpp"

using namespace std;

class MockVecContainer: public Container {
    public:
    vector<Base*> vec;
    MockVecContainer() {
        Op* t1 = new Op(2);
        Op* t2 = new Op(1);
        Op* t3 = new Op(3);
        vec.push_back(t1);
        vec.push_back(t2);
        vec.push_back(t3);
        sort_function = new BSort;
    }
    void add_element(Base* element) {}
    // iterate through trees and output the expressions (use stringify())
    void print() {}
    // calls on the previously set sorting-algorithm.
    //Checks if sort_function is not null, throw exception if otherwise
    void sort() {sort_function->sort(this);}
    /* Essentially the only functions needed to sort */
    //switch tree locations
    void swap(int i, int j) {}
    // get top ptr of tree at index i
    Base* at(int i) {}
    // return container size
    int size() {}

};



int main() { //Does operation (2 - 4)^(0.5*4) // This equals 4.
    Op O1(2.0); // will first stringify, then evaluate and display.
    Op O2(4.0);
    Op O3(0.5);
    Op O4(4.0);
    
    Op* T1 = new Op(10);
    Op* T2 = new Op(-1);
    ListContainer Mock(new SSort);
    
    Add* Addtest = new Add(T1, T2);
    cout << "size: " << Mock.size() << endl;
    Mock.add_element(T1);
    Mock.add_element(T2);
    Mock.add_element(Addtest);
    Mock.add_element(new Op(4));
    Mock.add_element(new Op(7));
    Mock.add_element(new Op(0));
    cout << "size: " << Mock.size() << endl;
    cout << "value: " << endl;
    cout << Mock.at(0)->evaluate() << endl;
    cout << Mock.at(1)->evaluate() << endl;
    cout << Mock.at(2)->evaluate() << endl;
    Mock.sort();
    cout << "value: " << endl;
    cout << Mock.at(0)->evaluate() << endl;
    cout << Mock.at(1)->evaluate() << endl;
    cout << Mock.at(2)->evaluate() << endl;
    cout << Mock.at(3)->evaluate() << endl;
    cout << Mock.at(4)->evaluate() << endl;
    cout << Mock.at(5)->evaluate() << endl;
    Mock.print();
    // cout << "Calling Mock Print:" << endl;
    // Mock.print();
    // cout << endl << endl;
    // //cout << Mock.size() << endl; //output should be 3
    // cout << "Printing evals" << endl;
    // cout << Mock.at(0)->evaluate() << endl << Mock.at(1)->evaluate() << endl << Mock.at(2)->evaluate() << endl; //Output should be 2, 2, 4
    
    
    // Mock.sort();
    // cout << "Calling Mock Print:" << endl;
    // Mock.print();
    // cout << "Printing evals:" << endl;
    // cout << Mock.at(0)->evaluate() << endl << Mock.at(1)->evaluate() << endl << Mock.at(2)->evaluate() << endl;
    
    // return 0;
}
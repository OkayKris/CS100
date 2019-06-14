#ifndef __CONTAINER_HPP__
#define __CONTAINER_HPP__

#include "sort.hpp"
#include "base.hpp"
#include "operators.hpp"
#include <vector>
#include <list>

using namespace std;

class Sort;
class Base;

class Container {
    protected:
        Sort* sort_function;
        
    public:
        /* Constructors */
        Container() : sort_function(nullptr) { };
        Container(Sort* function) : sort_function(function) { };

        /* Non Virtual Functions */
        void set_sort_function(Sort* sort_function); // set the type of sorting algorithm

        /* Pure Virtual Functions */
        // push the top pointer of the tree into container
        virtual void add_element(Base* element) = 0;
        // iterate through trees and output the expressions (use stringify())
        virtual void print() = 0;
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        virtual void sort() = 0;

        /* Essentially the only functions needed to sort */
        //switch tree locations
        virtual void swap(int i, int j) = 0;
        // get top ptr of tree at index i
        virtual Base* at(int i) = 0;
        // return container size
        virtual int size() = 0;
};

class ListContainer: public Container{
    protected:
        list<Base*> baseList;
    public: 
        ListContainer() {this->sort_function = 0;}
        ListContainer(Sort* function) {this->sort_function = function;}
        void add_element(Base* element);
        void print();
        void sort();
        void swap(int i, int j);
        Base* at(int i);
        int size();
};

class VectorContainer: public Container{
    protected:
        vector<Base*> vec;
    public:
        VectorContainer()  {this->sort_function = 0;}
        VectorContainer(Sort* function) { this->sort_function = function;}
        // push the top pointer of the tree into container
        void add_element(Base* element);
        // iterate through trees and output the expressions (use stringify())
        void print();
        // calls on the previously set sorting-algorithm.
        //Checks if sort_function is not null, throw exception if otherwise
        void sort();
        /* Essentially the only functions needed to sort */
        //switch tree locations
        void swap(int i, int j);
        // get top ptr of tree at index i
        Base* at(int i);
        // return container size
        int size();
};


#endif //__CONTAINER_HPP__

#include "container.hpp"
#include <bits/stdc++.h>
using namespace std;

void VectorContainer::add_element(Base* element){
    vec.push_back(element);
}

void VectorContainer::print(){
    string vecStr;
    for(unsigned i = 0; i < vec.size(); i++){
        vecStr = vec.at(i)->stringify();
        cout << vecStr << endl;
    }
}

void VectorContainer::sort(){
    try{
        if(this->sort_function != nullptr){
            sort_function->sort(this);
        }
    }
    catch(invalid_argument &e){
        cout << "Standard exception: " << e.what() << endl;
    }
}

void VectorContainer::swap(int i, int j){
    Base* temp;
    temp = vec.at(i);
    vec.at(i) = vec.at(j);
    vec.at(j) = temp;
    
}

Base* VectorContainer::at(int i){
    return vec.at(i);
}

int VectorContainer::size(){
    return vec.size();
}

void ListContainer::add_element(Base* element){
    baseList.push_back(element);
}

void ListContainer::print(){
    string listStr;
    for(list<Base*>::iterator i = baseList.begin(); i != baseList.end(); i++){
        //Base* j = *i;
        listStr = (*i)->stringify();
        cout << listStr << endl;
    }
}

void ListContainer::sort(){
    try{
        if(this->sort_function != nullptr){
            sort_function->sort(this);
        }
    }
    catch(invalid_argument &e){
        cout << "Standard exception: " << e.what() << endl;
    }
}
void ListContainer::swap(int i, int j){
    std::list<Base*>::iterator one = baseList.begin();
    for(int index = 0; index < i; ++index){
        ++one;
    }
    
    std::list<Base*>::iterator two = baseList.begin();
    for(int index = 0; index < j; ++index){
        ++two;
    }
    
    Base* temp = *one;
    *one = *two;
    *two = temp;
    
}

    
Base* ListContainer::at(int i){

    std::list<Base*>::iterator count = baseList.begin();
    for(int index = 0; index < i; ++index){
        ++count;
    }
    Base* j = *count;
    return j;
    
}

int ListContainer::size(){
    return baseList.size();
}

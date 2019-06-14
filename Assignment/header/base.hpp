#ifndef __BASE_HPP__
#define __BASE_HPP__
#include <iostream>
#include <vector>
using namespace std;
class base {
    protected:
        string command;
    public:
        virtual void execute() = 0;
};

#endif
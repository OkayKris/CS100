#ifndef __REDIRECTOR_HPP__
#define __REDIRECTOR_HPP__
#include "connector.hpp"
#include<fcntl.h> 

class Redirector {
    protected:
        bool pass;
        string executable;
        vector<string> arglist;
        string filename;
    public:
        Redirector() {};
        // Redirector(Connector* l1, string r1) {  // Constructor used in commandinput.cpp in the makeTree function
        //     left = l1;
        //     filename = r1;
        // }
        virtual void execute() = 0;
        // Connector* get_left() { return left; };
        // Connector* get_right() { return right; };
        bool passing() {return pass;};
};

#endif
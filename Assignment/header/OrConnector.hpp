#ifndef __ORCON_HPP__
#define __ORCON_HPP__
#include "connector.hpp"

class OrCon : public Connector {
    protected:
        //base* par;
        Connector* left;
        Connector* right;
        bool pass;
    public:
        OrCon(){};
        OrCon(Connector* l, Connector* r){ // Constructor used in commandinput.cpp in the makeTree function
            this->left = l;
            this->right = r;
        }
        void execute(){
            pass = true;
            left->execute();    // executes command/connector in left pointer
            if ((left->passing() == 0)) {
                right->execute();   // runs command since the other failed
                if ((right->passing() == 0)) {  // checks if the right command passed
                    pass = false;
                }
                else {
                  pass = true;
                }
            }
        }
        Connector* get_left() { return left; };
        Connector* get_right() { return right; };
        bool passing() {return pass;};
};

#endif
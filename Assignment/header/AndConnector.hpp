#ifndef __ANDCONNECTOR_HPP__
#define __ANDCONNECTOR_HPP__
#include "connector.hpp"

class AndCon : public Connector {
    private:
        bool pass;
        Connector* left;
        Connector* right;
    public:
        AndCon() {};
        AndCon(Connector* l1, Connector* r1) {  // Constructor used in commandinput.cpp in the makeTree function
            left = l1;
            right = r1;
        }
        void execute() {
            pass = true;
            left->execute();    // executes command/connector in left pointer
            if (left->passing() != 0) {
                right->execute();   // runs command since the other succeeded
                if ((right->passing() == 0)) {  // checks if the right command passed
                    pass = false;
                }
            }
            else {
                pass = false;
            }
        };
        Connector* get_left() { return left; };
        Connector* get_right() { return right; };
        bool passing() {return pass;};
};

#endif
#ifndef __PIPECONNECTOR_HPP__
#define __PIPECONNECTOR_HPP__
#include "connector.hpp"

class PipeCon : public Connector {
    private:
        bool pass;
        Connector* left;
        Connector* right;
    public:
        PipeCon() {};
        PipeCon(Connector* l1, Connector* r1) {  // Constructor used in commandinput.cpp in the makeTree function
            left = l1;
            right = r1;
        }
        // need to fix the execute function for piping
        void execute() {
            int status;
            pid_t leftID, rightID;
            
            leftID = fork();
            
            // if(pipe(piper) < 0) {
            //     pass = false;
            //     perror("Pipe could not be initialized\n");
            //     return;
            // }
            
            if (leftID == 0) {
                int piper[2];
            
                pipe(piper);
                
                rightID = fork();
                
                if (rightID == 0) {
                    close(piper[0]);
                    dup2(piper[1],1);
                    left->execute();
                    exit(0);
                }
                
                else {
                    close(piper[1]);
                    dup2(piper[0], 0);
                    wait(&status);
                    right->execute();
                    exit(0);
                }
            
            }
            
            else {
                wait(&status);
                return;
            }
        };
        Connector* get_left() { return left; };
        Connector* get_right() { return right; };
        bool passing() {return pass;};
};

#endif
#ifndef __READER_HPP__
#define __READER_HPP__
#include "connector.hpp"
#include "Redirection.hpp"

class Reader : public Redirector {
    protected:
        bool pass;
        string executable;
        vector<string> arglist;
        string filename;
    public:
        Reader(string e, vector<string> al, string fn) {
            executable = e;
            arglist = al;
            filename = fn;
        };
        // Redirector(Connector* l1, string r1) {  // Constructor used in commandinput.cpp in the makeTree function
        //     left = l1;
        //     filename = r1;
        // }
        void execute() {
            char* argexec = new char;   // used for turning found exec string into a char pointer for execvp
            char** argumentlist = new char* [arglist.size()+2];     // used for turning vector string of argumentlists into an char pointer array of char pointers for execvp
            argumentlist[0] = new char[executable.size()];
            for (int i = 1; i < arglist.size()+2; i++) {    // allocates memory for each char pointer in the char pointer array
                if (i != arglist.size()+1) {
                    argumentlist[i] = new char[arglist.at(i-1).size()];
                }
                else {
                    argumentlist[i] = NULL; // makes sure the last char pointer in the array has a NULL value
                }
            }
            strcpy(argexec, executable.c_str());    // copies the executable string to the argexec char pointer
            strcpy(argumentlist[0], executable.c_str());
            for (int i = 1; i < arglist.size()+1; i++) { // copies the arglist vector of strings to the char pointer array or char pointers
                strcpy(argumentlist[i], arglist.at(i-1).c_str());
            }
            char* fn = new char;
            strcpy(fn, filename.c_str());
            int filed = open(fn, O_RDONLY);
            
            if (filed < 0) {
                pass = false;
                printf("Error opening the file\n");
                return;
            }
            
            
            pid_t ID;
            ID = fork();
            if (ID == 0) {  // child process
                // cout << "In the child, " << argexec << " "; //<< endl;
                // for (int i = 0; i < arglist.size(); i++) {
                //     cout << argumentlist[i] << " ";
                // }
                // cout << endl;
                dup2(filed, 0);
                //char* buff = new char;
                
                //read(filed, buff, 20);
                //cout << buff;
                if (executable == "exit") {
                    exit(0);
                }
                execvp(argexec, argumentlist);
                perror("execvp failed");
                exit(3);
                }
            else if (ID > 0) {  // parent process
                int status;
                waitpid(ID, &status, WUNTRACED);
                if (status != 0) {
                    pass = false;   // assigned when command fails
                }
                if (executable == "exit") {
                    exit(0);    // checks to see if string is exit to exit shell
                }
            }
        };
        // Connector* get_left() { return left; };
        // Connector* get_right() { return right; };
        bool passing() {return pass;};
};

#endif
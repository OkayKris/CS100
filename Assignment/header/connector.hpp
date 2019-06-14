#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__
#include "base.hpp"
#include "test.hpp"
#include <vector>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <cstdlib>
#include "Redirection.hpp"
#include "Addon.hpp"
#include "Overwrite.hpp"
#include "Read.hpp"
//#include "PipeConnector.hpp"

class Connector {
    protected:
        string command; // has one full command stored here
        bool pass;
    public:
        Connector() {};
        virtual void execute() { // executes fork, waitpid, and execvp
            pass = true;
            string executable = "";
            vector<string> arglist; 
            string argument = "";
            for (int i = 0; i < command.size(); i++) { // uses assigned command string to then separate the exec string and argumentlist vector of strings from the command string
                if (command.at(i) != ' ') {
                    if (executable == "") { // gets exec string here
                        while((i < command.size()) && (command.at(i) != ' ')) {
                            executable.push_back(command.at(i));
                            i++;
                        }
                    }
                    else {  // gets arglist vector of strings here
                        if (argument == "") {
                            if (command.at(i) == '>') { // checks for redirection cases
                                if (command.at(i+1) == '>') {
                                    string file = "";
                                    for(int j = i+3; j < command.size() && command.at(j) != ' '; j++) {
                                        if (command.at(j) == ')') {
                                            break;
                                        }
                                        file.push_back(command.at(j));
                                    }
                                    Addon* t = new Addon(executable, arglist, file);
                                    t->execute();
                                    pass = t->passing();
                                    return;
                                }
                                else {
                                    string file = "";
                                    for(int j = i+2; j < command.size() && command.at(j) != ' '; j++) {
                                        if (command.at(j) == ')') {
                                            break;
                                        }
                                        file.push_back(command.at(j));
                                    }
                                    Overwriter* t = new Overwriter(executable, arglist, file);
                                    t->execute();
                                    pass = t->passing();
                                    return;
                                }
                            }
                            else if (command.at(i) == '<') {
                                string file = "";
                                for(int j = i+2; j < command.size() && command.at(j) != ' '; j++) {
                                    if (command.at(j) == ')') {
                                        break;
                                    }
                                    file.push_back(command.at(j));
                                }
                                Reader* t = new Reader(executable, arglist, file);
                                t->execute();
                                pass = t->passing();
                                return;
                            }
                            while ((i < command.size()) && (command.at(i) != ' ') ) {
                                argument.push_back(command.at(i));
                                i++;
                            }
                            if (argument != "") {
                                arglist.push_back(argument);
                                argument = "";
                            }
                        }
                    }
                }
            }
            // beginning of fork execvp and waitpid
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
            if (executable == "test") {
              test* t = new test(argumentlist);
              t->execute();
              pass = t->passing();
              return;
            }
            else {
              pid_t ID;
              ID = fork();
              if (ID == 0) {  // child process
                  // cout << "In the child, " << argexec << " "; //<< endl;
                  // for (int i = 0; i < arglist.size(); i++) {
                  //     cout << argumentlist[i] << " ";
                  // }
                  // cout << endl;
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
                  //wait(NULL);
                  if (status != 0) {
                      pass = false;   // assigned when command fails
                  }
                  if (executable == "exit") {
                      exit(0);    // checks to see if string is exit to exit shell
                  }
              }
            }
            return;
        };
        
        void set_cmd(string st) { command = st; };
        virtual bool passing() {return pass;};
};

#endif
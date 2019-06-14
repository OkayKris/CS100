#ifndef __RSHELL_HPP__
#define __RHSELL_HPP__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class rshell {
    private:
        string userInput;
    public:
        rshell() {};
        void execute() {
            string str = "";
            cout << "$ ";
            getline(cin, str);
            cout << endl;
            userInput = str;
            cout << "hello";
            return;
        };
        string get_input() { 
            return userInput; };
};

#endif
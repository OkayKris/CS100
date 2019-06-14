#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "connector.hpp"

using namespace std;

class test {
  private:
    bool pass;
    char** AL;
    int Reg(const char* str) {
      struct stat R;
      stat(str, &R);
      return S_ISREG(R.st_mode);
    };
    int Dir(const char* str) {
      struct stat D;
      stat(str, &D);
      return S_ISDIR(D.st_mode);
    }; 
  
  public:
    test(char** arglist) {AL = arglist;};
    void execute() {
      if (AL[1] == NULL) {
        cout << "(False)" << endl;
        pass = false;
        return;
      }
      string a = AL[1];
      
      if (a == "-f" && Reg(AL[2])) {
        cout << "(True)" << endl;
        pass = true;
        return;
      }
      
      else if (a == "-d" && Dir(AL[2])) {
        cout << "(True)" << endl;
        pass = true;
        return;
      }
      else if (a == "-e" && (Reg(AL[2]) || Dir(AL[2]))) {
        cout << "(True)" << endl;
        pass = true;
        return;
      }
      else if (AL[2] == NULL && (Reg(AL[1]) || Dir(AL[1]))) {
        cout << "(True)" << endl;
        pass = true;
        return;
      }
      else {
        cout << "(False)" << endl;
        pass = false;
        return;
      }
    };
    bool passing() {return pass;};
};
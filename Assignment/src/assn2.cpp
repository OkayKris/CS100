#include "../header/connector.hpp"
#include "../header/OrConnector.hpp"
#include "../header/AndConnector.hpp"
#include "../header/rshell.hpp"
#include "../header/commandinput.hpp"

using namespace std;

int main() {
    while(1) {
        string str;
        cout << "$ ";
        getline(cin, str);
        // rshell* shell = new rshell();
        // shell->execute();
        // // cout << "hello";
        // string ui = shell->get_input();
        CommandInput* run = new CommandInput(str);
        vector<string> cmdlist = run->get_commands();
        Connector* execcmd;
        for (int i = 0; i < cmdlist.size(); i++) {
            execcmd = run->makeTree(cmdlist.at(i));
            execcmd->execute();
        }
    }
    return 0;
}
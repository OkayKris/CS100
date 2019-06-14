#ifndef __COMMANDINPUT_HPP__
#define __COMMANDINPUT_HPP__
#include <string>
#include <cstdlib>
#include "PipeConnector.hpp"

class CommandInput {
    private:
        vector<string> commands;
    public:
        CommandInput(){};
        CommandInput(string input){
            string command;
            int open = 0;
            int closed = 0;
            for(int i = 0; i < input.size(); i++){
                if(input.at(i) == '('){
                    open++;
                }
                if(input.at(i) == ')'){
                    closed++;
                }
            }
            if(open != closed){
                perror("Uneven number of parenthesis");
                return;
            }
            for (int i = 0; i < input.size(); i++) { // takes in the long string with all commands from rshell
                if (input.at(i) != ';' && input.at(i) != '\n') { // then separates each command into the string vector
                    if (input.at(i) == '"') {
                        do {
                            command += input.at(i);
                            i += 1;
                        } while(input.at(i) != '"');
                        // command += input.at(i);
                        //cout << command << i;
                        // command += input.at(i);
                    }
                    else if (input.at(i) == '[') {
                      do {
                            command += input.at(i);
                            i += 1;
                        } while(input.at(i) != ']');
                    }
                    else if (input.at(i) == '(') {
                      do {
                            command += input.at(i);
                            i += 1;
                        } while(input.at(i) != ')');
                    }
                    else if (input.at(i) == '#') {  // ends command if it ends with #
                        commands.push_back(command);
                        return;
                    }
                    else if ((i > 0) && (input.at(i-1) == ';')) {   // checks to add spaces after a semicolon
                        do {
                            i += 1;
                        } while(input.at(i) == ' ');
                    }
                    if (i < input.size()) { // add command from input string
                        command += input.at(i);
                    }
                    if (i+1 < input.size()) {
                        if (input.at(i+1) == ';' || input.at(i+1) == '\n') {    //ends collected command string from the input and pushes it to the back of the vector string of commands
                            commands.push_back(command);
                            command = "";
                            i += 1;
                        }
                    }
                    else if (i+1 >= input.size()) { // pushes back command in string is i >= input.size()
                        commands.push_back(command);
                        command = "";
                        i += 1;
                    }
                }
            }
        };
        
        Connector* makeTree(string cmd) {   // creates tree based on given string of commands in source file
            string right;
            for (int i = cmd.size()-1; i >= 0; i--) {   // checks to see if string has quotes to prevent it from being recognized by the & and | if statements
                if (cmd.at(i) == '"') {
                    do {    // uses loop to capture entire string in quotes
                        i -= 1;
                        right.insert(0, 1, cmd.at(i));
                    } while (cmd.at(i-1) != '"'); 
                    i -= 1;
                }
                else if (cmd.at(i) == ']') {
                  do {    // uses loop to capture command in brackets
                        i -= 1;
                        right.insert(0, 1, cmd.at(i));
                    } while (cmd.at(i-1) != '['); 
                    right.insert(0, 1, 't');
                    right.insert(0, 1, 's');
                    right.insert(0, 1, 'e');
                    right.insert(0, 1, 't');
                    i -= 1;
                }
                //else if (cmd.at(i) == ')') {
                //  do {    // uses loop to capture command in parenthesis
                //        i -= 1;
                //        right.insert(0, 1, cmd.at(i));
                //    } while (cmd.at(i-1) != '('); 
                //    i -= 1;
                //}
                else if (cmd.at(i) == ')') {  // recognize when there is a parenthesis input
                    int counter = 1;
                    while (counter != 0 && i >= 0) {  //creates string for command captured in parenthesis
                        i -= 1;
                        if (cmd.at(i) == '(') {
                            counter -= 1;
                            if (counter == 0) {break;}
                        }
                        else if (cmd.at(i) == ')') {counter += 1;}
                        right.insert(0, 1, cmd.at(i));
                    }
                    if (i != 0) {  // case when there is a connector following the parenthesis
                        i -= 3;
                        string left;
                        for (int j = 0; j < i-1; j++) {
                            left.push_back(cmd.at(j));
                        }
                        if (cmd.at(i) == '|' && cmd.at(i+1) == '|') {
                            cout << left << endl;
                            Connector* c1 = makeTree(left); // sets node for left command
                            cout << right << endl;
                            Connector* c2 = makeTree(right);    // connector used for right command
                            // cout << left << endl << right << ":)";
                            //c2->set_cmd(right); //  sets node for right command
                            OrCon* orcmd = new OrCon(c1, c2);   // sets a new orcmd node as parent node
                            return orcmd; // used in this function
                        }
                        else if (cmd.at(i) == '&' && cmd.at(i+1) == '&') {
                            Connector* c1 = makeTree(left);
                            Connector* c2 = makeTree(right);
                            // cout << left << endl << right;
                            //c2->set_cmd(right);
                            AndCon* andcmd = new AndCon(c1,c2);
                            return andcmd;
                        }
                    }
                    else { // when parenthesis is at i=0, need to assemble tree for encapsuled code when there are no following connectors
                        Connector* rightcmd = makeTree(right);
                        return rightcmd;
                    }
                    
                }
                else if (cmd.at(i) == '|' && cmd.at(i+1) == '|') {  // separates commands used by or connector
                    string left;
                    
                    for (int j = 0; j < i-1; j++) { // separates the left command of or connector
                        left.push_back(cmd.at(j));
                    }
                    Connector* c1 = makeTree(left); // sets node for left command
                    Connector* c2 = new Connector();    // connector used for right command
                    // cout << left << endl << right << ":)";
                    c2->set_cmd(right); //  sets node for right command
                    OrCon* orcmd = new OrCon(c1, c2);   // sets a new orcmd node as parent node
                    return orcmd; // used in this function
                }
                else if (cmd.at(i) == '&' && cmd.at(i+1) == '&') {  // sames as above with and chars
                    string left;
                    for (int j = 0; j < i-1; j++) {
                        left.push_back(cmd.at(j));
                    }
                    Connector* c1 = makeTree(left);
                    Connector* c2 = new Connector();
                    // cout << left << endl << right;
                    c2->set_cmd(right);
                    AndCon* andcmd = new AndCon(c1,c2);
                    return andcmd;
                }
                else if (i > 0 && cmd.at(i) == '|' && cmd.at(i+1) == ' ' && cmd.at(i-1) != '|') {
                    string left;
                    for (int j = 0; j < i-1; j++) {
                        left.push_back(cmd.at(j));
                    }
                    Connector* c1 = makeTree(left);
                    Connector* c2 = new Connector();
                    // cout << left << endl << right;
                    c2->set_cmd(right);
                    PipeCon* pipecmd = new PipeCon(c1,c2);
                    return pipecmd;
                }
                else {
                    if (cmd.at(i) == '|' || cmd.at(i) == '&') {}    // checks to make sure that the chars used in the if statements above
                    else {
                        if ((i > 0) && ((cmd.at(i-1) == ('&')) || (cmd.at(i-1) == ('|'))) && (cmd.at(i) == ' ')){}  // same as above but checking that the chars added are not the chars wanted in the command list
                        else {
                            right.insert(0, 1, cmd.at(i));  // creates right command
                        }
                    }
                }
                
            }
            Connector* rightcmd = new Connector();
            rightcmd->set_cmd(right);   // sets right command connector pointer's string to the right command string
            return rightcmd;
        };
        vector<string> get_commands() {return commands;};
};

#endif
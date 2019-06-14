#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "../head/command.hpp"
#include "../head/base.hpp"
#include "../head/operators.hpp"
#include "../head/sort.hpp"
#include "../head/container.hpp"
#include "../head/base_factory.hpp"
#include "../head/factory.hpp"
#include <vector>

using namespace std;

class Menu {
    private:
        int history_index; // Indexes which command was last executed, accounting for undo and redo functions
        std::vector<Command*> history; // Holds all the commands that have been executed until now

    public:
        Menu() {
            history_index = -1;
        }

        std::string execute() {
            if(history_index == -1) return "Empty";
            return to_string(history.at(history_index)->execute());
        }

        std::string stringify() {
            if(history_index == -1) return "Empty";
            return history.at(history_index)->stringify();
        }

        bool initialized() {
            if(history.size() == 0) return false;
            else if (history_index == -1) return false;
            else return true;
        }

        void add_command(Command* cmd) {
            while(history_index != history.size() - 1) history.pop_back();
            history.push_back(cmd);
            
            ++history_index;
        }

        Command* get_command() {
            return history.at(history_index);
        }

        void undo() {
            if (history_index > -1) --history_index;
            else return;
        }

        void redo() {
            if (history_index < history.size() - 1) ++history_index;
            else return;
        }
};

#endif
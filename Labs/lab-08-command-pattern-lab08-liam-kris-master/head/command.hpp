#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include "../head/command.hpp"
#include "../head/base.hpp"
#include "../head/operators.hpp"
#include "../head/sort.hpp"
#include "../head/container.hpp"
#include "../head/base_factory.hpp"
#include "../head/factory.hpp"

class Command {
    protected:
        Base* root;
    
    public:
        Command() { this->root = nullptr; }
        double execute() { return root->evaluate(); }
        std::string stringify() { return root->stringify(); }
        Base* get_root() { return root; }
};

class InitialCommand : public Command {
    
    public:
    InitialCommand(Base* b) { this->root = b; }
};

class AddCommand : public Command {
    
    public:
    AddCommand(Command* cmd, Base* b) { this->root = new Add(cmd->get_root(), b); }
};

class SubCommand : public Command {
    
    public:
    SubCommand(Command* cmd, Base* b) { this->root = new Sub(cmd->get_root(), b); }
};

class MultCommand : public Command {
    
    public:
    MultCommand(Command* cmd, Base* b) { this->root = new Mult(cmd->get_root(), b); }
};

class DivCommand : public Command {
    
    public:
    DivCommand(Command* cmd, Base* b) { this->root = new Div(cmd->get_root(), b); }
};

class PowCommand : public Command {
    
    PowCommand(Command* cmd, Base* b) { this->root = new Pow(cmd->get_root(), b); }
};

#endif

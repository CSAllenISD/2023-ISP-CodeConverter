#ifndef VARIABLE_H
#define VARIABLE_H


#include "Value.h"
class Variable
{
    public:
        Variable(std::string line, bool cons);
        void defineTypes();
        std::string define(std::map<std::string, std::string> vars_n, std::map<std::string, bool> libs);
        void typeFinder(bool beq);
        std::string retName();
        std::string retType();
        std::string operations(std::string new_l, std::map<std::string, std::string> vars_n);
        std::string op_line(std::string op, std::string l, std::map<std::string, std::string> vars_n);
    private:
        std::string line;
        bool cons;
        std::string name;
        std::string value;
        std::string type;
        std::map<std::string, std::string> types;
        Value val;
};

#endif
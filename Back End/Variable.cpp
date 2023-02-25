#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "headers/Variable.h"
#include "headers/Value.h"

Variable::Variable(std::string line, bool cons)
{
    this->line = line;
    this->cons = cons;
    this->val = Value();
}
void Variable::defineTypes(){
    types["Boolean"] = "bool";
    types["Int"] = "int";
    types["Double"] = "double";
    types["String"] = "std::string";
}
void Variable::typeFinder(bool beq){
    if (!beq){
        type = types[value];
        value = "NULL";
        return;
    }
    if (value.rfind("\"", 0) == 0){
        type = "std::string";
        return;
    }
    if (value.find(".") == -1){
        type = "int";
        return;
    }
    type = "double";
}
std::string Variable::define(std::map<std::string, std::string> vars_n){
    bool beq = true;
    int eq = line.find("=");
    if (eq == -1){
        beq = false;
        eq = line.find(":");
    }
    name = line.substr(3,eq-3);
    value = line.substr(eq+1,line.size());
    value = val.convert(value, vars_n);
    typeFinder(beq);
    std::string newl = type + " " + name;
    if (value != "NULL"){
        newl += (" = " + value);
    }
    newl += ";";
    return newl;

    //std::cout << "Name: " << name << std::endl;
    //std::cout << "Value: " << value << std::endl;
}
std::string Variable::retName(){
    return name;
}
std::string Variable::retType(){
    return type;
}
std::string Variable::operations(std::string l, std::map<std::string, std::string> vars_n){
    char operation = l[name.size()];
    switch (operation){
        case '=':
            return op_line("=",l,vars_n);
        case '+':
            return op_line("+=",l,vars_n);
        case '-':
            return op_line("-=",l,vars_n);
        case '*':
            return op_line("*=",l,vars_n);
        case '/':
            return op_line("/=",l,vars_n);
        default:
            return " ";
    }
}

std::string Variable::op_line(std::string op, std::string l, std::map<std::string, std::string> vars_n){
    std::string tempVal = l.substr(name.size() + op.size(), l.size());
    std::string v = val.convert(line, vars_n);
    std::string fin = name + " " + op + " " + v + ";";
    return fin;
}
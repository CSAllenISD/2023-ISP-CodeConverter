#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "headers/Value.h"
#include "headers/Function.h"
#include "headers/Variable.h"

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
std::string Variable::define(std::map<std::string, std::string> vars_n, std::map<std::string, bool> libs, std::map<std::string, Function> funcs){
    bool beq = true;
    int eq = line.find("=");
    if (eq == -1){
        beq = false;
        eq = line.find(":");
    }
    name = line.substr(3,eq-3);
    value = line.substr(eq+1,line.size());
    std::vector<std::string> result = val.convert(value, vars_n, funcs);
    value = result[0];
    type = result[1];
    if (result[1] == "unknown"){ 
        typeFinder(beq);
    }
    if (result[2] != "unknown"){
        libs[result[2]] = true;
    }
    std::string newl = type + " " + name;
    if (value != "NULL"){
        newl += (" = " + value);
    }
    newl += ";";
    return newl;
}
std::string Variable::retName(){
    return name;
}
std::string Variable::retType(){
    return type;
}
std::string Variable::operations(std::string l, std::map<std::string, std::string> vars_n, std::map<std::string, Function> funcs){
    char operation = l[name.size()];
    switch (operation){
        case '=':
            return op_line("=",l,vars_n, funcs);
        case '+':
            return op_line("+=",l,vars_n, funcs);
        case '-':
            return op_line("-=",l,vars_n, funcs);
        case '*':
            return op_line("*=",l,vars_n, funcs);
        case '/':
            return op_line("/=",l,vars_n, funcs);
        default:
            return l;
    }
}

std::string Variable::op_line(std::string op, std::string l, std::map<std::string, std::string> vars_n, std::map<std::string, Function> funcs){
    std::string tempVal = l.substr(name.size() + op.size(), l.size());
    std::string v = val.convert(tempVal, vars_n, funcs)[0];
    std::string fin = name + " " + op + " " + v + ";";
    return fin;
}
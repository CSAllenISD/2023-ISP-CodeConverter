#include <iostream>
#include <string>
#include <map>
#include "headers/Variable.h"


Variable::Variable(std::string line, bool cons)
{
    this->line = line;
    this->cons = cons;
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
std::string Variable::define(){
    bool beq = true;
    int eq = line.find("=");
    if (eq == -1){
        beq = false;
        eq = line.find(":");
    }
    name = line.substr(3,eq-3);
    value = line.substr(eq+1,line.size());
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

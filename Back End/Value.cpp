#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "headers/Variable.h"
#include "headers/Value.h"

Value::Value(){
    int n;
}
std::vector<std::string> Value::convert(std::string line, std::map<std::string, std::string> vars_n){
    std::vector<std::string> l;
    l.push_back(line);
    l.push_back("unknown");
    auto it{vars_n.cbegin()};
    for (auto const& [key, val] : vars_n){
        if (line.rfind(key,0) == 0){
            std::string swiftVarFunc = line.substr(key.size(),line.size());
            std::vector<std::string> newFunc = varFunctions(swiftVarFunc, val);
            std::string newL = key + newFunc[0];
            l[0] = newL;
            l[1] = newFunc[1];
            return l;
        }
    }
    return l;
}

std::vector<std::string> Value::varFunctions(std::string func, std::string type){
    //inneficient and sloppy as hell but I will fix later, I'm too tired
    std::vector<std::string> l;
    l.push_back(func);
    l.push_back("TYPE NOT FOUND");
    if (type == "std::string"){
        if (func == ".count"){
            l[0] = ".size()";
            l[1] = "int";
            return l;
        }
    }
    return l;
}
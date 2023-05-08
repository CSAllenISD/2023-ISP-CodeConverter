#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "headers/Variable.h"
#include "headers/Function.h"
#include "headers/Value.h"

Value::Value(){
    int n;
}
std::vector<std::string> Value::convert(std::string line, std::map<std::string, std::string> vars_n, std::map<std::string, Function> funcs){
    std::vector<std::string> l;
    l.push_back(line);
    l.push_back("unknown");
    l.push_back("unknown");
    auto it{vars_n.cbegin()};
    auto its{funcs.cbegin()};
    for (auto const& [key, val] : vars_n){
        if (line.rfind(key,0) == 0){
            std::string swiftVarFunc = line.substr(key.size(),line.size());
            std::vector<std::string> newFunc = varFunctions(swiftVarFunc, val);
            std::string newL = key + newFunc[0];
            l[0] = newL;
            l[1] = newFunc[1];
            l[2] = newFunc[2];
            return l;
        }
    }
    for (auto [key, val] : funcs){
        if (line.rfind(key,0) == 0){
            l[0] = val.call(line);
            l[1] = val.retType();
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
    l.push_back("unknown");
    if (type == "std::string"){
        if (func == ".count"){
            l[0] = ".size()";
            l[1] = "int";
            l[2] = "vector";
            return l;
        }
    }
    return l;
}
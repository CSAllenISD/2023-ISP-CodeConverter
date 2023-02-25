#include <iostream>
#include <string>
#include <map>
#include "headers/Variable.h"
#include "headers/Value.h"

Value::Value(){
    int n;
}
std::string Value::convert(std::string line, std::map<std::string, std::string> vars_n){
    auto it{vars_n.cbegin()};
    for (auto const& [key, val] : vars_n){
        if (line.rfind(key,0) == 0){
            std::string swiftVarFunc = line.substr(key.size(),line.size());
            std::string newFunc = varFunctions(swiftVarFunc, val);
            std::string newL = key + newFunc;
            return newL;
        }
    }
    return line;
}

std::string Value::varFunctions(std::string func, std::string type){
    //inneficient and sloppy as hell but I will fix later, I'm too tired
    if (type == "std::string"){
        if (func == ".count"){
            return ".size()";
        }
    }
    return func;
}
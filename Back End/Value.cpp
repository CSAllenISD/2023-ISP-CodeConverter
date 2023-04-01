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
    std::vector<std::string> var;
    var.push_back(line);
    var.push_back("unknown");
    
    auto it{vars_n.cbegin()};
    for (auto const& [key, val] : vars_n){
        if (line.rfind(key,0) == 0){
            std::string swiftVarFunc = line.substr(key.size(),line.size());
            std::vector<std::string> newFunc = varFunctions(swiftVarFunc, val);
            std::string newL = key + newFunc[0];
            newFunc[0] = newL;
            return newFunc;
        }
    }
    return var;
}

std::vector<std::string> Value::varFunctions(std::string func, std::string type){
    //inneficient and sloppy as hell but I will fix later, I'm too tired
    std::vector<std::string> var;
    var.push_back(func);
    var.push_back("TYPE NOT FOUND");
    if (type == "std::string"){
        if (func == ".count"){
            var[0] = ".size()";
            var[1] = "double";
            return var;
        }
    }
    return var;
}
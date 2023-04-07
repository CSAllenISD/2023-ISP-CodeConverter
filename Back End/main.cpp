#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "headers/Variable.h"
#include "headers/Loops.h"
#include "headers/Print.h"
#include "headers/Value.h"
#include "headers/Scope.h"
#include "headers/Function.h"
void print_vector(std::vector<std::string> vec){
    for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << std::endl;
    }
}
std::vector<std::string> takeInput() {
    std::vector<std::string>  value;
    for (std::string line; std::getline(std::cin, line);){
        value.push_back(line);
    }
    return value;
}
std::vector<std::string>  remove_spaces(std::vector<std::string>  raw){
    std::vector<std::string> newOne;
    for (int i = 0; i < raw.size(); i++){
        std::string emp;
        bool inQuote = false;
        for (int j = 0; j < raw[i].length(); j++){
            if (raw[i][j] == '\"'){
                inQuote = !inQuote;
            }
            if (!isspace(raw[i][j]) || inQuote){
                emp = emp + raw[i][j];
            } 
        }
        newOne.push_back(emp);
    }
    return newOne;
}

int isVariableChange(std::string line, std::vector<Variable> vars){
    for (int i = 0; i < vars.size(); i++){
        if (line.rfind(vars[i].retName()) == 0) {
            return i;
        }
    }
    return -1;
}
std::string isFuncCall(std::string line, std::map<std::stringFunction> funcs){
    auto it{funcs.cbegin()};
    for (auto const& [name, func] : vars_n){
        if (line.rfind(name) == 0) {
            return name;
        }
    }
    return " ";
}
std::string checkKeyword(std::string line, std::vector<Variable> &vars, std::map<std::string, std::string> &vars_n, std::vector<Function> &funcs, Scope &scope){
    int varIndex = isVariableChange(line, vars);
    std::string funcIndex = isFuncCall(line, funcs);
    std::string tabbing = scope.scopeTabbing();
    tabbing = tabbing.substr(0,tabbing.length()-1);
    if (line.rfind("var", 0) == 0) {
        Variable tempVar = Variable(line, false);
        tempVar.defineTypes();
        std::string ret = tempVar.define(vars_n);
        vars.push_back(tempVar);
        vars_n[tempVar.retName()] = tempVar.retType();
        return tabbing + ret;
    }
    if (line.rfind("if", 0) == 0) {
        Loops tempLoops = Loops();
        scope.increaseScope();
        return tabbing + tempLoops.ifConversion(line);
    }
    if (line.rfind("print",0) == 0){
        Print print = Print();
        return tabbing + print.conversion(line);
    }
    if (line.rfind("for",0) == 0){
        Loops tempLoops = Loops();
        scope.increaseScope();
        return tabbing + tempLoops.forConversion(line);
    }
    if (line.rfind("repeat",0) == 0){
        Loops tempLoops = Loops();
        scope.increaseScope();
        return tabbing + tempLoops.rptwhileConversion(line);
    }
    if (line.rfind("func",0) == 0){
        Function tempFunction = Function();
        funcs.push_back(tempFunction);
        scope.increaseScope();
        return tabbing + tempFunction.define(line);
    }
    if (line.rfind("}",0) == 0){
        scope.decreaseScope();
        tabbing = scope.scopeTabbing();
        tabbing = tabbing.substr(0,tabbing.length()-1);
        return tabbing + "}";
    }
    if (varIndex != -1){
        return vars[varIndex].operations(line, vars_n);
    }
    if (funcIndex != " "){
        return funcs[funcIndex].call(line);
    }
    return " ";
}

int main() {
    std::vector<Variable> variables;
    std::map<std::string, std::string> vars_n;
    std::map<std::string,Function> functions;
    std::vector<std::string> lines = remove_spaces(takeInput());
    std::vector<std::string> finalCode;
    Scope scope = Scope();
    for (int i; i < lines.size(); i++){
        std::string newl = checkKeyword(lines[i], variables, vars_n, functions, scope);
        finalCode.push_back(newl);
    }
    print_vector(finalCode);
    return 0;
}
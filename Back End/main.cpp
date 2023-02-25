#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "headers/Variable.h"
#include "headers/Loops.h"
#include "headers/Print.h"

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
std::string checkKeyword(std::string line, std::vector<Variable> &vars){
    int varIndex = isVariableChange(line, vars);
    if (varIndex != -1){
        return vars[varIndex].operations(line);
    }
    if (line.rfind("var", 0) == 0) {
        Variable tempVar = Variable(line, false);
        tempVar.defineTypes();
        std::string ret = tempVar.define();
        vars.push_back(tempVar);
        return ret;
    }
    if (line.rfind("if", 0) == 0) {
        Loops tempLoops = Loops();
        return tempLoops.ifConversion(line);
    }
    if (line.rfind("print",0) == 0){
        Print print = Print();
        return print.conversion(line);
    }
    return " ";
}

int main() {
    std::vector<Variable> variables;
    std::vector<std::string> lines = remove_spaces(takeInput());
    //print_vector(lines);  
    std::vector<std::string> finalCode;
    for (int i; i < lines.size(); i++){
        std::string newl = checkKeyword(lines[i], variables);
        finalCode.push_back(newl);
    }
    print_vector(finalCode);
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "headers/Variable.h"

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
std::string checkKeyword(std::string line){
    if (line.rfind("var", 0) == 0) {
        Variable tempVar = Variable(line, false);
        tempVar.defineTypes();
        return tempVar.define();
    }
    return " ";
}

int main() {
    std::vector<std::string> lines = remove_spaces(takeInput());
    //print_vector(lines);
    std::vector<std::string> finalCode;
    for (int i; i < lines.size(); i++){
        std::string newl = checkKeyword(lines[i]);
        finalCode.push_back(newl);
    }
    print_vector(finalCode);
    //std::vector<Variable> variables;
    return 0;
}
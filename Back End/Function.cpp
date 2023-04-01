#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "headers/Function.h"

Function::Function(){
    defineTypes();
}


void Function::defineTypes(){
    types["Boolean"] = "bool";
    types["Int"] = "int";
    types["Double"] = "double";
    types["String"] = "std::string";
}
std::string Function::define(std::string line){
    int nameStart = 4;
    int nameEnd = line.find("(");
    std::string name = line.substr(nameStart,nameEnd - nameStart);
    int funcParEnd = line.find(")");
    std::string parametersStr = line.substr(nameEnd, funcParEnd - nameEnd+1);
    int colonIndex = (parametersStr.find(":") != std::string::npos) ? (parametersStr.find(":")) : 0;
    do{
        int commaIndex = (parametersStr.find(",") != std::string::npos) ? (parametersStr.find(",")) : parametersStr.length();
        if (colonIndex != 0){
            std::string parameter = parametersStr.substr(1, colonIndex-1);
            std::string swiftType = parametersStr.substr(colonIndex + 1, commaIndex - colonIndex -2);
            std::string type = types[swiftType];
            parameters[parameter] = type;
            parametersStr = (commaIndex < parametersStr.length()) ? parametersStr.substr(commaIndex + 1): " ";
            colonIndex = (parametersStr.find(":") != std::string::npos) ? (parametersStr.find(":")) : 0;
        }
    } while (colonIndex != 0);
    std::string returnClause = line.substr(funcParEnd+1);
    int arrow = (returnClause.find(">") != std::string::npos) ? (returnClause.find(">")) : 0;
    std::string returnType = "void";
    if (arrow != 0){
        returnType = types[returnClause.substr(arrow+1,returnClause.length()-arrow-2)];
    }
    std::ostringstream finalLine;
    finalLine << returnType << " " << name << "(";
    auto it{parameters.cbegin()};
    for (auto const& [param, type] : parameters){
        finalLine << type << " " << param << ", ";
    }
    std::string tempS = finalLine.str();
    //std::cout << tempS.find_last_of(",") << tempS.length() << std::endl;
    if (tempS.find_last_of(",") == tempS.length() - 2){
        tempS = tempS.substr(0, tempS.length() - 2);
    }
    //std::cout << tempS << "s" <<  std::endl;
    tempS += ("){");
    return tempS;
}
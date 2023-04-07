#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "headers/Function.h"

Function::Function(){
    defineTypes();
}

std::string Function::retName(){
    return name;
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
    name = line.substr(nameStart,nameEnd - nameStart);
    int funcParEnd = line.find(")");
    std::string parametersStr = line.substr(nameEnd+1, funcParEnd - nameEnd - 1);
    int colonIndex = (parametersStr.find(":") != std::string::npos) ? (parametersStr.find(":")) : 0;
    do{
        int commaIndex = (parametersStr.find(",") != std::string::npos) ? (parametersStr.find(",")) : parametersStr.length();
        if (colonIndex != 0){
            std::string parameter = parametersStr.substr(0, colonIndex);
            std::string swiftType = parametersStr.substr(colonIndex + 1, commaIndex - colonIndex - 1);
            std::string type = types[swiftType];
            parameters[parameter] = type;
            paramArr.push_back(parameter);
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
    for (int i=0; i < paramArr.size(); i++){
        finalLine << parameters[paramArr[i]] << " " << paramArr[i] << ", ";
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
std::string Function::call(std::string line){
    std::vector<std::string> args;
    std::string argString = line.substr(name.length() + 1, line.length() - name.length() - 1);
    int colonIndex = (argString.find(":") != std::string::npos) ? (argString.find(":")) : 0;
    do {
        int commaIndex = (argString.find(",") != std::string::npos) ? (argString.find(",")) : argString.length();
        if (colonIndex != 0){
            std::string parameter = argString.substr(0, colonIndex);
            std::string argument = argString.substr(colonIndex + 1, commaIndex - colonIndex - 1);
            args.push_back(argument);
            argString = (commaIndex < argString.length()) ? argString.substr(commaIndex + 1): " ";
            colonIndex = (argString.find(":") != std::string::npos) ? (argString.find(":")) : 0; 
        }
    } while (colonIndex != 0);
    std::string ret = name + "(";
    for (int i = 0; i < args.size(); i++){
        ret += args[i] + ", ";
    }
    if (args.size() != 0) {
        ret = ret.substr(0, ret.length() - 2); 
    }
    ret += (");");
    return ret;
}

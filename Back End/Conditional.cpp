#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "headers/Conditional.h"

Conditional::Conditional(){
    defineOperations();
}

void Conditional::defineOperations(){
    operations.push_back("==");
    operations.push_back("!=");
    operations.push_back("<=");
    operations.push_back(">=");
}
std::string Conditional::make(std::line){
    do{
        int commaIndex = (argString.find(",") != std::string::npos) ? (argString.find(",")) : argString.length();
        if (colonIndex != 0){
            std::string parameter = argString.substr(0, colonIndex);
            std::string argument = argString.substr(colonIndex + 1, commaIndex - colonIndex - 1);
            args.push_back(argument);
            argString = (commaIndex < argString.length()) ? argString.substr(commaIndex + 1): " ";
            colonIndex = (argString.find(":") != std::string::npos) ? (argString.find(":")) : 0;
            }
    } while(colonIndex != 0)
}
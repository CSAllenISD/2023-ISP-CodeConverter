#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "headers/Loops.h"

Loops::Loops(){
    int r;
}
std::string Loops::ifConversion(std::string line) {
    int startLength = 2;
    int endLength = line.length() - startLength;
    std::string ifContent = line.substr(startLength, endLength - 1);
    std::ostringstream ifFormat;
    ifFormat << "if" << " " << "(" << ifContent << ")" << " " << "{";
    // Causes the current index to contain the new, converted C++ code.
    return ifFormat.str();
} 


std::string Loops::forConversion(std::string line) {
    int startLength = 3;
    int inIndex = line.find("in");
    int endLength = line.length() - startLength;
    std::string varName = line.substr(startLength, inIndex - startLength);
    std::string range = line.substr(inIndex + 2, endLength - 1);
    std::string forContent;
    if (range.find("..") == std::string::npos){
        forContent = line.substr(inIndex+2, endLength - 1);
    }
    else {
        std::string num1 = range.substr(0,range.find("."));
        std::string num2 = range.substr(range.find(".") + 3, range.length());
        std::string include = "<";
        if (range.substr(range.find(".") + 2, 1) == "."){
            include += "<=";
        }
        forContent = ("int" + varName + "=" + num1 + ";" + varName + include + "num2;" + varName + "++");
    }
    std::ostringstream forFormat;
    forFormat << "for" << " " << "(" << forContent << ")" << " " << "{";
    // Causes the current index to contain the new, converted C++ code.
    return forFormat.str();
}

std::string Loops::whileConversion(std::string line) {
    return line;
}

std::string Loops::rptwhileConversion(std::string line) {
    return "do {";
}

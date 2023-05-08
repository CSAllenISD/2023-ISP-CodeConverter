#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "headers/Conditional.h"
#include "headers/Loops.h"

Loops::Loops(){
    int r;
}
std::string Loops::ifConversion(std::string line) {
    int startLength = 2;
    int endLength = line.length() - startLength;
    std::string ifContent = line.substr(startLength, endLength - 1);
    //ifContent = con.make(ifContent);
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
    std::string range = line.substr(inIndex + 2, endLength - inIndex);
    std::string forContent;
    forContent = "int " + varName + " : " + range;
    if (range.find("..") != std::string::npos){
        std::string num1 = range.substr(0,range.find("."));
        std::string num2 = range.substr(range.find(".") + 3, range.length());
        std::string include = "<";
        if (range.substr(range.find(".") + 2, 1) == "."){
            include += "=";
        }
        forContent = ("int " + varName + " = " + num1 + "; " + varName + " " + include + " " + num2 + "; " + varName + "++");
    }
    std::ostringstream forFormat;
    forFormat << "for" << " " << "(" << forContent << ")" << " " << "{";
    // Causes the current index to contain the new, converted C++ code.
    return forFormat.str();
}

std::string Loops::whileConversion(std::string line) {
    int startLength = 5;
    int endLength = line.length() - startLength;
    std::string whileContent = line.substr(startLength, endLength - 1);
    //ifContent = con.make(ifContent);
    std::ostringstream whileFormat;
    whileFormat << "while" << " " << "(" << whileContent << ")" << " " << "{";
    // Causes the current index to contain the new, converted C++ code.
    return whileFormat.str();
}

std::string Loops::rptwhileConversion(std::string line) {
    return "do {";
}
std::string Loops::elseConversion(std::string line) {
    if (line.find("if") == std::string::npos){
        return "else {";
    }
    else {
        int startLength = 6;
        int endLength = line.length() - startLength;
        std::string ifContent = line.substr(startLength, endLength - 1);
        //ifContent = con.make(ifContent);
        std::ostringstream ifFormat;
        ifFormat << "else if" << " " << "(" << ifContent << ")" << " " << "{";
        // Causes the current index to contain the new, converted C++ code.
        return ifFormat.str();
    }
}
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
    return line;
    }


std::string Loops::whileConversion(std::string line) {
    return line;
    }
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "headers/Print.h"

Print::Print(){
    int n;
}
std::string Print::conversion(std::string line) {
    // The next 3 lines work to create a substring, containing all of the text inside the parinthesis of a print statement.
    int requiredLength = 6;
    int endLength = line.length() - requiredLength;
    std::string printContent = line.substr(requiredLength, endLength - 1);
    // Creates a string with the syntax of a C++ print statement, along with the content inside the parinthesis of the original print statment.
    std::ostringstream varInStr;
    varInStr << "std::cout <<" << " " << printContent << ";";
    // Causes the current index to contain the new, converted C++ code.
    return varInStr.str();
}
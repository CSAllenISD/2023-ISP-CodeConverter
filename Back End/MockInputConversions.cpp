#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Creating a Mock Input
std::vector<std::vector<std::string> > mockInput
{
    {"print(\"quotesTest\")"},
    {"print(noQuotesTest)"},
    {"print(multipleOnOneLineTest)", "print(multipleOnOneLineTest)"},
    {"not a print test"},
    {"if testVar1 = testVar2 {"}
};

// Function to print the indexes of a 2d array
void printVector(std::vector<std::vector<std::string> > testArr) {
    for (int i = 0; i < testArr.size(); i++)
    {
        for (int j = 0; j < testArr[i].size(); j++)
        {
            std::cout << testArr[i][j] << " ";
        }    
        std::cout << std::endl;
    }

};

class printStatements {
// Class dedicated to the conversion of print statements from swift to c++

    public:
     std::vector<std::vector<std::string> > Conversion(std::vector<std::vector<std::string> > testArr) {
        for (int i = 0; i < testArr.size(); i++) {

            for (int j = 0; j < testArr[i].size(); j++) {
                // Looks for "print(" in each index of the array to determine weather there is a print statement or not.
                size_t found = testArr[i][j].find("print()", 0, 6);

                if (found != std::string::npos) {
                    // The next 3 lines work to create a substring, containing all of the text inside the parinthesis of a print statement.
                    int requiredLength = 6;
                    int endLength = testArr[i][j].length() - requiredLength;
                    std::string printContent = testArr[i][j].substr(requiredLength, endLength - 1);

                    // Creates a string with the syntax of a C++ print statement, along with the content inside the parinthesis of the original print statment.
                    std::ostringstream varInStr;
                    varInStr << "std::cout <<" << " " << printContent << ";";

                    // Causes the current index to contain the new, converted C++ code.
                    testArr[i][j] = varInStr.str();
                    
                }
                else {
                    testArr[i][j] = testArr[i][j];
                };
            };
        };
        return testArr;
    };



};

class Loops {
// Class dedicated to the conversion of print statements from swift to c++

    public:
        std::vector<std::vector<std::string> > ifConversion(std::vector<std::vector<std::string> > testArr) {
            for (int i = 0; i < testArr.size(); i++) {

                for (int j = 0; j < testArr[i].size(); j++) {

                    // Looks for "if" in each index of the array to determine weather there is a print statement or not.
                    std::string myStr = testArr[i][j];
                    std::string startStr = myStr.substr(0, 2);
                    size_t found = startStr.find("if");

                    if (found != std::string::npos) {
                        // The next 3 lines work to create a substring, containing all of the text after the word "if".
                        int startLength = 3;
                        int endLength = testArr[i][j].length() - startLength;
                        std::string ifContent = testArr[i][j].substr(startLength, endLength - 1);

                        std::ostringstream ifFormat;
                        ifFormat << "if" << " " << "(" << ifContent << ")" << " " << "{";

                        // Causes the current index to contain the new, converted C++ code.
                        testArr[i][j] = ifFormat.str();
                    } else {
                        testArr[i][j] = testArr[i][j];
                    };
                };
            };
            return testArr;
        };


        std::vector<std::vector<std::string> > forConversion(std::vector<std::vector<std::string> > testArr) {
            return testArr;
        };


        std::vector<std::vector<std::string> > whileConversion(std::vector<std::vector<std::string> > testArr) {
            return testArr;
        };
};






printStatements print = printStatements();
Loops loops = Loops();

int main() {
    std::vector<std::vector<std::string> > printCheck = print.Conversion(mockInput);
    std::vector<std::vector<std::string> > ifCheck = loops.ifConversion(printCheck);
    printVector(ifCheck);
};
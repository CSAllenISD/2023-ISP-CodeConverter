#include <iostream>
#include <string>
#include <vector>
#include <sstream>


std::vector<std::vector<std::string> > mockInput
{
    {"print(\"quotesTest\")"},
    {"print(noQuotesTest)"},
    {"print(multipleOnOneLineTest)", "print(multipleOnOneLineTest)"},
    {"not a print test"}
};


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

class Conversions {

    public:
     std::vector<std::vector<std::string> > printConversion(std::vector<std::vector<std::string> > testArr) {
        for (int i = 0; i < testArr.size(); i++) {

            for (int j = 0; j < testArr[i].size(); j++) {
                size_t found = testArr[i][j].find("print()", 0, 6);

                if (found != std::string::npos) {
                    int requiredLength = 6;
                    int endLength = testArr[i][j].length() - requiredLength;
                    std::string printContent = testArr[i][j].substr(requiredLength, endLength - 1);

                    std::ostringstream varInStr;
                    varInStr << "std::cout <<" << " " << printContent << ";";

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

Conversions conversions = Conversions();

int main() {
    std::vector<std::vector<std::string> > printCheck = conversions.printConversion(mockInput);
    printVector(printCheck);
};

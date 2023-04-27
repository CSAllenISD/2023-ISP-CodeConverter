#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// Creating a Mock Input
std::vector<std::vector<std::string> > mockInput
{
    {"print(\"quotesTest\")"},
    {"print(noQuotesTest)"},
    {"print(multipleOnOneLineTest)", "print(multipleOnOneLineTest)"},
    {"not a print test"},
    {"if testVar1 = testVar2 {"},
    {"while testVar1 = testVar2 {"},
    {"var apple = [apple, bannana]"}
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
    for (int i = 0; i < testArr.size(); i++) {

      for (int j = 0; j < testArr[i].size(); j++) {

	// Looks for "for" in each index of the array to determine weather there is a for statement or not.
	std::string myStr = testArr[i][j];
	std::string startStr = myStr.substr(0, 5);
	size_t found = startStr.find("while");

	if (found != std::string::npos) {
	  // The next 3 lines work to create a substring, containing all of the text after the word "if".
	  int startLength = 6;
	  int endLength = testArr[i][j].length() - startLength;
	  std::string whileContent = testArr[i][j].substr(startLength, endLength - 1);

	  std::ostringstream whileFormat;
	  whileFormat << "while" << " " << "(" << whileContent << ")" << " " << "{";

	  // Causes the current index to contain the new, converted C++ code.
	  testArr[i][j] = whileFormat.str();
	} else {
	  testArr[i][j] = testArr[i][j];
	};
      };
    };
	  
    return testArr;
  };
};

class Array {

public:  
  
  std::vector<std::vector<std::string> > declarationConversion(std::vector<std::vector<std::string> > testArr) {
    for (int i = 0; i < testArr.size(); i++) {

      for (int j = 0; j < testArr[i].size(); j++) {
	std::string myStr = testArr[i][j];
	size_t found = myStr.find("[");
	size_t found2 = myStr.find("var");
	size_t found3 = myStr.find("let");

	if (found != std::string::npos) {
	  if (found2 != std::string::npos || found3 != std::string::npos) {
	    myStr.erase(0, 3);
	    std::replace( myStr.begin(), myStr.end(), '[', '{');
	    std::replace( myStr.begin(), myStr.end(), ']', '}');
	    std::ostringstream arrayFormat;
	    arrayFormat << "std::vector<auto>" << myStr;
	    testArr[i][j] = arrayFormat.str();
	  }
	}else{
	  testArr[i][j] = testArr[i][j];
	};
      };
    };
    return testArr;
  };
};




printStatements print = printStatements();
Loops loops = Loops();
Array array = Array();

int main() {
  std::vector<std::vector<std::string> > printCheck = print.Conversion(mockInput);
  std::vector<std::vector<std::string> > ifCheck = loops.ifConversion(printCheck);
  std::vector<std::vector<std::string> > whileCheck = loops.whileConversion(ifCheck);
  std::vector<std::vector<std::string> > arrayCheck = array.declarationConversion(whileCheck);
  
  printVector(arrayCheck);
};

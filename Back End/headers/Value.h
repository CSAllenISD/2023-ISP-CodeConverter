#ifndef VALUE_H
#define VALUE_H

#include "Function.h"
class Value
{
    public:
        Value();
        std::vector<std::string> convert(std::string line,std::map<std::string, std::string> vars_n,  std::map<std::string, Function> funcs);
        std::vector<std::string> varFunctions(std::string func, std::string type);
};
#endif
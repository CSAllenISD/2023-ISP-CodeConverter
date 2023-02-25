#ifndef VALUE_H
#define VALUE_H

class Value
{
    public:
        Value();
        std::string convert(std::string line,std::map<std::string, std::string> vars_n);
        std::string varFunctions(std::string func, std::string type);
};
#endif
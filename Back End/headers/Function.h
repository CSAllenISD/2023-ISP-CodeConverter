#ifndef FUNCTION_H
#define FUNCTION_H

class Function 
{
    public:
        Function();
        std::string retName();
        std::string define(std::string line);
        std::string call(std::string line);
        void printParams();
        void defineTypes();
    private:
        std::vector<std::string> paramArr;
        std::string name;
        std::map<std::string, std::string> parameters;
        std::map<std::string, std::string> types;
};
#endif
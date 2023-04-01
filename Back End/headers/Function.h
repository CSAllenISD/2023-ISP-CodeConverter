#ifndef FUNCTION_H
#define FUNCTION_H

class Function 
{
    public:
        Function();
        std::string define(std::string line);
        void defineTypes();
    private:
        std::map<std::string, std::string> parameters;
        std::map<std::string, std::string> types;
};
#endif
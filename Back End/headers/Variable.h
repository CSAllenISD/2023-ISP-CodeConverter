#ifndef VARIABLE_H
#define VARIABLE_H

class Variable
{
    public:
        Variable(std::string line, bool cons);
        std::string line;
        bool cons;
        std::string name;
        std::string value;
        std::string type;
        std::map<std::string, std::string> types;
        void defineTypes();
        std::string define();
        void typeFinder(bool beq);
    private:
    
};

#endif
#ifndef VARIABLE_H
#define VARIABLE_H

class Variable
{
    public:
        Variable(std::string line, bool cons);
        void defineTypes();
        std::string define();
        void typeFinder(bool beq);
        std::string retName();
        std::string operations(std::string new_l);
        std::string op_line(std::string op, std::string l);
    private:
        std::string line;
        bool cons;
        std::string name;
        std::string value;
        std::string type;
        std::map<std::string, std::string> types;
};

#endif
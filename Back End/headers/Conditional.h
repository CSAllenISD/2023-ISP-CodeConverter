#ifndef CONDITIONAL_H
#define CONDITIONAL_H

class Conditional 
{
    public:
        Conditional();
        void defineOperators();
        std::string make(std::string line);
        int checkConditional(std::string line);
    private:
        std::vector<std::string> operators;
};
#endif
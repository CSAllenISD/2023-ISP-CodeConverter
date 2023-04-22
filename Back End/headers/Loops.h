#ifndef LOOPS_H
#define LOOPS_H

#include "Conditional.h"

class Loops
{
    public:
        Loops();
        std::string ifConversion(std::string line);
        std::string forConversion(std::string line);
        std::string whileConversion(std::string line);
        std::string rptwhileConversion(std::string line);
    private:
        Conditional con;
};

#endif
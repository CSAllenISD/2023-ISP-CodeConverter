#ifndef LIBRARIES_H
#define LIBRARIES_H

class Libraries 
{
    public:
        Libraries();
        std::map<std::string, bool> return_libs();
    private:
        std::map<std::string, bool>libs;
};
#endif
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "headers/Loops.h"
#include "headers/Conditional.h"

Conditional::Conditional(){
    defineOperators();
}

void Conditional::defineOperators(){
    operators.push_back("==");
    operators.push_back("!=");
    operators.push_back(">");
    operators.push_back("<");
    operators.push_back("<=");
    operators.push_back(">=");
}
int Conditional::checkConditional(std::string line){
    int op = 4;
    bool oor = true;
    for (int i = 0; i < operators.size(); i++){
        //std::cout << line.find(operators[i]) << " " << i << std::endl;
        //std::cout << operators[i] << " " << op << std::endl;
        if ((line.find(operators[i]) <= line.find(operators[op])) && (line.find(operators[i]) > -1)){
            //std::cout << "wtf    " << i << std::endl;
            oor = false;
            op = i;
        }
    }
    if (oor){
        return operators.size();
    }
    return op;
}
std::string Conditional::make(std::string line){
    std::string temp = line;
    //std::cout << line << std::endl;
    int op = checkConditional(line);
    int tempOp = 0;
    std::string oper = operators[op];
    int opIndex = line.find(oper);
    int oldOp = 0;
    std::string ret = "(";
    std::cout << oper << " " << op << " " << opIndex;
    //std::cout << "crazy" << ret << std::endl;
    //std::cout << opIndex << " crazy " << ret << std::endl;
    while ((opIndex != -1) && (opIndex != temp.size())){
        //std::cout << "wtf";
        //std::cout << opIndex << std::endl;
        ret += (temp.substr(0, opIndex) + " " + operators[op] + " ");
        temp = temp.substr(opIndex + operators[op].size(), temp.size() - opIndex - operators[op].size());
        oldOp = opIndex;
        tempOp = op; 
        op = checkConditional(temp);
        opIndex = temp.find(operators[op]);
        //std::cout << oldOp << " " << opIndex << std::endl;
        //std::cout << line << std::endl;
        //std::cout << "crazy" << ret << std::endl;
    }
    //std::cout << "hello" << std::endl;
    ret += temp.substr(oldOp + operators[tempOp].size(), temp.size() - oldOp - operators[tempOp].size()) + ")";
    //std::cout << "crazy" << ret << std::endl;
    return ret;
}
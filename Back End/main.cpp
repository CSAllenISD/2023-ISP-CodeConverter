#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<tuple>
#include "headers/Variable.h"
#include "headers/Loops.h"
#include "headers/Print.h"
#include "headers/Value.h"
#include "headers/Scope.h"
#include "headers/Function.h"
#include "headers/Conditional.h"
#include "headers/Libraries.h"
void print_libs(std::map<std::string, bool> libs){
    auto it{libs.cbegin()};
    for (auto const& [lib, tf] : libs){
        std::cout << "#include <"<< lib << ">" << std::endl;
    }
}
void print_vector(std::vector<std::string> vec){
    for (int i = 0; i < vec.size(); i++) {
            std::cout << vec[i] << std::endl;
    }
}
std::vector<std::string> takeInput() {
    std::vector<std::string>  value;
    for (std::string line; std::getline(std::cin, line);){
        value.push_back(line);
    }
    return value;
}
std::vector<std::string>  remove_spaces(std::vector<std::string>  raw){
    std::vector<std::string> newOne;
    for (int i = 0; i < raw.size(); i++){
        std::string emp;
        bool inQuote = false;
        for (int j = 0; j < raw[i].length(); j++){
            if (raw[i][j] == '\"'){
                inQuote = !inQuote;
            }
            if (!isspace(raw[i][j]) || inQuote){
                emp = emp + raw[i][j];
            } 
        }
        newOne.push_back(emp);
    }
    return newOne;
}
int isVariableChange(std::string line, std::vector<Variable> vars){
    for (int i = 0; i < vars.size(); i++){
        if (line.rfind(vars[i].retName(),0) == 0) {
            return i;
        }
    }
    return -1;
}
std::string isFuncCall(std::string line, std::map<std::string,Function> funcs){
    auto it{funcs.cbegin()};
    for (auto const& [name, func] : funcs){
        if (line.rfind(name, 0) == 0) {
            return name;
        }
    }
    return " ";
}
std::tuple<std::string, std::string> checkKeyword(std::string line, std::vector<Variable> &vars, std::map<std::string, std::string> &vars_n, std::map<std::string, Function> &funcs, Scope &scope, std::map<std::string, bool> &libs){
    int varIndex = isVariableChange(line, vars);
    std::string funcIndex = isFuncCall(line, funcs);
    std::string tabbing = scope.scopeTabbing();
    tabbing = tabbing.substr(0,tabbing.length()-1);
    if (line.rfind("var", 0) == 0) {
        Variable tempVar = Variable(line, false);
        tempVar.defineTypes();
        std::string ret = tempVar.define(vars_n, libs, funcs);
        vars.push_back(tempVar);
        vars_n[tempVar.retName()] = tempVar.retType();
        return std::make_tuple((tabbing + ret),scope.scopeName());
    }
    if (line.rfind("let", 0) == 0) {
        Variable tempVar = Variable(line, false);
        tempVar.defineTypes();
        std::string ret = tempVar.define(vars_n, libs, funcs);
        vars.push_back(tempVar);
        vars_n[tempVar.retName()] = tempVar.retType();
        return std::make_tuple((tabbing + ret),scope.scopeName());
    }
    if (line.rfind("return", 0) == 0) {
        std::string ret = "return " + line.substr(6,line.size());
        return std::make_tuple(tabbing + ret,scope.scopeName());
    }
    if (line.rfind("if", 0) == 0) {
        Loops tempLoops = Loops();
        scope.increaseScope();
        return std::make_tuple((tabbing + tempLoops.ifConversion(line)), scope.scopeName());
    }
    if (line.rfind("print",0) == 0){
        Print print = Print();
        return std::make_tuple(tabbing + print.conversion(line), scope.scopeName());
    }
    if (line.rfind("for",0) == 0){
        Loops tempLoops = Loops();
        scope.increaseScope();
        return std::make_tuple(tabbing + tempLoops.forConversion(line), scope.scopeName());
    }
    if (line.rfind("while",0) == 0){
        Loops tempLoops = Loops();
        scope.increaseScope();
        return std::make_tuple(tabbing + tempLoops.whileConversion(line), scope.scopeName());
    }
    if (line.rfind("repeat",0) == 0){
        Loops tempLoops = Loops();
        scope.increaseScope();
        return std::make_tuple(tabbing + tempLoops.rptwhileConversion(line), scope.scopeName());
    }
    if (line.rfind("func",0) == 0){
        Function tempFunction = Function();
        std::string l = tempFunction.define(line);
        funcs[tempFunction.retName()] = (tempFunction);
        scope.increaseScope();
        scope.changeScope(tempFunction.retName());
        return std::make_tuple(tabbing + l, scope.scopeName());
    }
    if (line.rfind("else",0) == 0){
        Loops tempLoops = Loops();
        scope.increaseScope();
        return std::make_tuple((tabbing + tempLoops.elseConversion(line)), scope.scopeName());
    }
    if (line.rfind("}",0) == 0){
        std::string curr =  scope.scopeName();
        scope.decreaseScope();
        scope.removeFunc();
        tabbing = scope.scopeTabbing();
        tabbing = tabbing.substr(0,tabbing.length()-1);
        return std::make_tuple(tabbing + "}", curr);
    }
    if (line.rfind("//") == 0){
        return std::make_tuple(tabbing + line, scope.scopeName());
    }
    if (varIndex != -1){
        return std::make_tuple(tabbing + vars[varIndex].operations(line, vars_n, funcs), scope.scopeName());
    }
    if (funcIndex != " "){
        //funcs[funcIndex].printParams();
        return std::make_tuple(tabbing + funcs[funcIndex].call(line) + ";", scope.scopeName());
    }
    return std::make_tuple(" ",scope.scopeName());
}

int main() {
    std::vector<Variable> variables;
    std::map<std::string, std::string> vars_n;
    std::map<std::string,Function> functions;
    std::vector<std::string> lines = remove_spaces(takeInput());
    std::vector<std::string> finalCode;
    std::vector<std::string> mainFunction;
    std::vector<int> finalScopes;
    Libraries lib = Libraries();
    std::map<std::string, bool> libs = lib.return_libs();
    Scope scope = Scope();
    std::string str = "p";
    str.insert(0, 5,' ');
    std::string tabbing = str.substr(0,str.length()-1);
    for (int i; i < lines.size(); i++){
        //std::cout << lines[i] << std::endl;
        //std::cout << "HERE3" << std::endl;
        finalScopes.push_back(scope.retScope());
        std::tuple newl = checkKeyword(lines[i], variables, vars_n, functions, scope, libs);
        if (std::get<1>(newl) == "main"){
            mainFunction.push_back(tabbing + std::get<0>(newl));
        }
        else{
            //std::cout << lines[i] << std::endl;
            finalCode.push_back(std::get<0>(newl));
        }
    }
    print_libs(libs);
    print_vector(finalCode);
    std::cout << "int main() {" << std::endl;
    print_vector(mainFunction);
    std::cout << tabbing + "return 0;" << std::endl << "}" << std::endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>
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
void print_funcs(std::vector<std::string> vec, std::vector<int> scope){ 
    for (int i = 0; i < vec.size(); i++) {
        if (scope[i] != 0){
            std::cout << vec[i] << std::endl;
        }
    }
}
void print_main(std::vector<std::string> vec, std::vector<int> scope){
    std::cout << "int main() {"; 
    std::string str = "p";
    str.insert(0, 5,' ');
    std::string tabbing = str.substr(0,str.length()-1);
    for (int i = 0; i < vec.size(); i++) {
        if (scope[i] == 0){
            std::cout << tabbing << vec[i] << std::endl;
        }
    }
    std::cout << "}" << std::endl;
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
        if (line.rfind(vars[i].retName()) == 0) {
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
std::string checkKeyword(std::string line, std::vector<Variable> &vars, std::map<std::string, std::string> &vars_n, std::map<std::string, Function> &funcs, Scope &scope, std::map<std::string, bool> &libs){
    int varIndex = isVariableChange(line, vars);
    std::string funcIndex = isFuncCall(line, funcs);
    std::string tabbing = scope.scopeTabbing();
    tabbing = tabbing.substr(0,tabbing.length()-1);
    if (line.rfind("var", 0) == 0) {
        Variable tempVar = Variable(line, false);
        tempVar.defineTypes();
        std::string ret = tempVar.define(vars_n, libs);
        vars.push_back(tempVar);
        vars_n[tempVar.retName()] = tempVar.retType();
        return tabbing + ret;
    }
    if (line.rfind("if", 0) == 0) {
        Loops tempLoops = Loops();
        scope.increaseScope();
        return tabbing + tempLoops.ifConversion(line);
    }
    if (line.rfind("print",0) == 0){
        Print print = Print();
        return tabbing + print.conversion(line);
    }
    if (line.rfind("for",0) == 0){
        Loops tempLoops = Loops();
        scope.increaseScope();
        return tabbing + tempLoops.forConversion(line);
    }
    if (line.rfind("repeat",0) == 0){
        Loops tempLoops = Loops();
        scope.increaseScope();
        return tabbing + tempLoops.rptwhileConversion(line);
    }
    if (line.rfind("func",0) == 0){
        Function tempFunction = Function();
        std::string l = tempFunction.define(line);
        funcs[tempFunction.retName()] = (tempFunction);
        scope.increaseScope();
        return tabbing + l;
    }
    if (line.rfind("}",0) == 0){
        scope.decreaseScope();
        tabbing = scope.scopeTabbing();
        tabbing = tabbing.substr(0,tabbing.length()-1);
        return tabbing + "}";
    }
    if (line.rfind("//") == 0){
        return tabbing + line;
    }
    if (varIndex != -1){
        return vars[varIndex].operations(line, vars_n);
    }
    if (funcIndex != " "){
        funcs[funcIndex].printParams();
        return funcs[funcIndex].call(line);
    }
    return " ";
}

int main() {
    std::vector<Variable> variables;
    std::map<std::string, std::string> vars_n;
    std::map<std::string,Function> functions;
    std::vector<std::string> lines = remove_spaces(takeInput());
    std::vector<std::string> finalCode;
    std::vector<int> finalScopes;
    Libraries lib = Libraries();
    std::map<std::string, bool> libs = lib.return_libs();
    Scope scope = Scope();
    for (int i; i < lines.size(); i++){
        finalScopes.push_back(scope.retScope());
        std::string newl = checkKeyword(lines[i], variables, vars_n, functions, scope, libs);
        finalCode.push_back(newl);
    }
    print_libs(libs);
    print_funcs(finalCode,finalScopes);
    print_main(finalCode,finalScopes);
    return 0;
}
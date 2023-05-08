#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "headers/Scope.h"

Scope::Scope(){
    scope = 0;
    currFunc = "main";
    currFuncLevel = 0;
    prevScope.push_back("main");
    prevScopeLevels.push_back(0);
}
void Scope::increaseScope(){
    scope += 1;
}
void Scope::decreaseScope(){
    scope -= 1;
}
int Scope::retScope(){
    return scope;
}
std::string Scope::scopeName(){
    return currFunc;
}
void Scope::addScope(std::string name){
    currentScope.push_back(name);
}
void Scope::removeScope(){
    currentScope.pop_back();
}
void Scope::changeScope(std::string func){
    prevScope.push_back(func);
    prevScopeLevels.push_back(scope);
    currFunc = func;
    currFuncLevel = scope;
}
void Scope::removeFunc(){
    // /std::cout << scope << std::endl << prevScopeLevels[prevScopeLevels.size()-1] << ;
    if (scope < prevScopeLevels[prevScopeLevels.size()-1]){
        //prevScope.erase(prevScope[prevScope.size()-1]);
        prevScope.pop_back();
        prevScopeLevels.pop_back();
        currFunc = prevScope[prevScope.size()-1];
        currFuncLevel = prevScopeLevels[prevScopeLevels.size()-1];
    }
}
std::string Scope::scopeTabbing(){
    std::string str = "p";
    str.insert(0, scope*5,' ');
    return str;
}
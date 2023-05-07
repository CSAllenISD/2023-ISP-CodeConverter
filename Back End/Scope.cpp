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
void Scope::changeScope(std::string func, int level;){
    prevScope.push_back(currFunc);
    prevScopeLevels.push_back(currFuncLevel);
    currFunc = func;
    currFuncLevel = level;
}
void Scope::removeFunc(){
    if (scope < prevScopeLevels[prevScopeLevels.size()-1]){
        prevScope.erase(prevScope[prevScope.size()-1]);
        prevScopeLevels.erase(prevScopeLevels[prevScopeLevels.size()-1]);
        currFunc = prevScope[prevScope.size()-1];
        currFuncLevel = prevScopeLevels[prevScopeLevels.size()-1];
    }
}
std::string Scope::scopeTabbing(){
    std::string str = "p";
    str.insert(0, scope*5,' ');
    return str;
}
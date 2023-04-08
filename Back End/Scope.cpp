#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "headers/Scope.h"

Scope::Scope(){
    scope = 0;
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
void Scope::addScope(std::string name){
    currentScope.push_back(name);
}
void Scope::removeScope(){
    currentScope.pop_back();
}
std::string Scope::scopeTabbing(){
    std::string str = "p";
    str.insert(0, scope*5,' ');
    return str;
}
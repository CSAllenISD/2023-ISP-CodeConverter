#ifndef SCOPE_H
#define SCOPE_H

class Scope {
    public:
        Scope();
        void increaseScope();
        void decreaseScope();
        int retScope();
        std::string scopeName();
        void changeScope(std::string func);
        void addScope(std::string name);
        void removeScope();
        void removeFunc();
        std::string scopeTabbing();
    private:
        int scope;
        std::vector<std::string> currentScope;
        std::string currFunc;
        int currFuncLevel;
        std::vector<std::string> prevScope;
        std::vector<int> prevScopeLevels;
};
#endif
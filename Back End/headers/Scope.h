#ifndef SCOPE_H
#define SCOPE_H

class Scope {
    public:
        Scope();
        void increaseScope();
        void decreaseScope();
        int retScope();
        void changeScope(std::string name)
        std::string scopeTabbing();
    private:
        int scope;
        std::vector<std::string> currentScope;
};
#endif
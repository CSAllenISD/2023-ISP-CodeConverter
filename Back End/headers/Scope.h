#ifndef SCOPE_H
#define SCOPE_H

class Scope {
    public:
        Scope();
        void increaseScope();
        void decreaseScope();
        int retScope();
        std::string scopeTabbing();
    private:
        int scope;
};
#endif
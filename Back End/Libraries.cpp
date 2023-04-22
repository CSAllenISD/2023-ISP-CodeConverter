#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "headers/Libraries.h"

Libraries::Libraries() {
    libs["iostream"] = true;
}

std::map<std::string, bool> Libraries::return_libs() {
    return libs;
}
#pragma once

#include <string>
using std::string;
using std::to_string;

#include "../general/defs.h"

typedef unsigned int UI;

class Unit {

    UI value;
    
    public: 
    Unit();
    Unit(UI);
    Unit(Unit const&) = default;
    
    ~Unit() = default;
    
    // Returns 0 if 1~9, 1 if 0, 2 if others
    UI usable() const;
    
    Unit &set(UI);
    UI get() const;
    
    string toString() const;
    
};

char putChar(Unit const&);

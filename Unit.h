#pragma once

#include <string>
using std::string;
using std::to_string;

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
    Unit &set(Unit const&);
    UI get() const;
    
    string toString() const;
    
};

char putChar(Unit const&);

#pragma once

#include <string>
using std::string;

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
    
    string toSring() const;
    
};

char putChar(Unit const&);

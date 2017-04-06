#pragma once

#include <vector>
#include <string>
using std::vector;
using std::string;

#include "Unit.h"
#include "Possibility.h"
#include "defs.h"

typedef vector<Unit> vu;
typedef vector<vu> vvu;
typedef vector<string> vstr;

class Board {
    
    vvu values;
    
    public:
    
    Board();
    
    string getRowString(UI) const;
    vstr getRowsVstr() const;
    string toString() const;
    void printBoard() const;
    
    
    
};

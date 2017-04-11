#pragma once

#include <vector>
#include <string>
using std::vector;
using std::string;

#include "Unit.h"
#include "../boardInterpret/Possibility.h"
#include "../general/defs.h"

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
    
    Unit &get(UI r, UI c);
    Unit const &get(UI r, UI c) const;
    
    /*
        The following three methods gets the n-th row/column/box. 
        The getBox method returns a 9-elem vector (for dim==3) which maps to the original box as:
            0 1 2
            3 4 5
            6 7 8
        For other dim's, the formation is similar.
    */
    vu getRow(UI) const noexcept;
    vu getCol(UI) const noexcept;
    vu getBox(UI) const noexcept;
    
    static Board debug_trivial();
    
};

void debug_vuPrint(vu const&);


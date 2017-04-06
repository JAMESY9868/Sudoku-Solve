#pragma once

#include <vector>
#include <string>
using std::vector;
using std::string;

#include "Unit.h"

#define BOARD_DIM 3
#define BOARD_SIZE (BOARD_DIM*BOARD_DIM)
// n ^ 2 + n + 1
#define BOARD_PRINT_SIZE (BOARD_DIM+BOARD_SIZE+1)

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

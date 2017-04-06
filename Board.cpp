#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

#include "Board.h"

Board::Board()
: values(BOARD_SIZE, vu(BOARD_SIZE, Unit()))
{ }

string Board::getRowString(UI row) const {
    // I think this deals with exception throwing whereas op[] does not
    return getRowsVstr().at(row);
}

vstr Board::getRowsVstr() const {
    /*
        + - - - + - - - + - - - +    00
        | 0 0 0 | 0 0 0 | 0 0 0 |
        | 0 0 0 | 0 0 0 | 0 0 0 |
        | 0 0 0 | 0 0 0 | 0 0 0 |
        + - - - + - - - + - - - +    04
        | 0 0 0 | 0 0 0 | 0 0 0 |
        | 0 0 0 | 0 0 0 | 0 0 0 |
        | 0 0 0 | 0 0 0 | 0 0 0 |
        + - - - + - - - + - - - +    08
        | 0 0 0 | 0 0 0 | 0 0 0 |
        | 0 0 0 | 0 0 0 | 0 0 0 |
        | 0 0 0 | 0 0 0 | 0 0 0 |
        + - - - + - - - + - - - +    12
    */
    vstr res = vstr(BOARD_PRINT_SIZE, "");
    auto shrinkIndex = [](UI n){return n-1-n/(1+BOARD_DIM);};
    for(UI i = 0; i < BOARD_PRINT_SIZE; i++)
        for(UI j = 0; j < BOARD_PRINT_SIZE; j++)
            res[i] += string() + (
                // the visible part
                #define _tmp (BOARD_DIM+1)
                0 == i % _tmp && 0 == j % _tmp ?
                '+' :
                0 == i % _tmp ?
                '-' :
                0 == j % _tmp ?
                '|' :
                putChar(values[shrinkIndex(i)][shrinkIndex(j)])
                #undef _tmp
            ) + (
                // the invisible part
                (j + 1 < BOARD_PRINT_SIZE) ?
                ' ' :
                '\0'
            );
    return res;
}

string Board::toString() const {
    string res = "";
    vstr const rowVStr = getRowsVstr();
    for(UI i = 0; i < rowVStr.size(); i++)
        res += rowVStr.at(i) + '\n';
    return res;
}

void Board::printBoard() const {
    cout << toString() << endl;
    return;
}

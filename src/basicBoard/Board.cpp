#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

#include "Board.h"

Board::Board()
: values(BOARD_SIZE, vu(BOARD_SIZE, Unit()))
{ }

string Board::getRowString(UI const row) const {
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

Unit &Board::get(UI const row, UI const col) {
    return values[row][col];
}

Unit const &Board::get(UI const row, UI const col) const {
    return values[row][col];
}

vu Board::getRow(UI const row) const noexcept {
    if(row >= BOARD_SIZE) // Error Checking
        return vu{};
    vu res = vu(BOARD_SIZE, Unit());
    for(UI j = 0; j < BOARD_SIZE; j++)
        res[j] = get(row, j);
    return res;
}

vu Board::getCol(UI const col) const noexcept {
    if(col >= BOARD_SIZE) // Error Checking
        return vu{};
    vu res = vu(BOARD_SIZE, Unit());
    for(UI i = 0; i < BOARD_SIZE; i++)
        res[i] = get(i, col);
    return res;
}

vu Board::getBox(UI const box) const noexcept {
    if(box >= BOARD_SIZE) // Error Checking
        return vu{};
    vu res = vu(BOARD_SIZE, Unit());
    #define _tmp1 (BOARD_DIM*(box%BOARD_DIM))
    #define _tmp2 (BOARD_DIM*(box/BOARD_DIM))
    for(UI i = 0; i < BOARD_DIM; i++)
        for(UI j = 0; j < BOARD_DIM; j++)
            res[i * BOARD_DIM + j] = get(_tmp2 + i, _tmp1 + j);
    return res;
    #undef _tmp1
    #undef _tmp2
}

Board Board::debug_trivial() {
    /* Output the following board:
            1 2 3 | 4 5 6 | 7 8 9
            4 5 6 | 7 8 9 | 1 2 3
            7 8 9 | 1 2 3 | 4 5 6
            - - - | - - - | - - -
            2 3 4 | 5 6 7 | 8 9 1
            5 6 7 | 8 9 1 | 2 3 4
            8 9 1 | 2 3 4 | 5 6 7
            - - - | - - - | - - -
            3 4 5 | 6 7 8 | 9 1 2
            6 7 8 | 9 1 2 | 3 4 5
            9 1 2 | 3 4 5 | 6 7 8
            
    */
    Board res = Board();
    
    for(UI R = 0; R < BOARD_DIM; R++)
        for(UI r = 0; r < BOARD_DIM; r++)
            for(UI col = 0; col < BOARD_SIZE; col++)
                res.get(R * BOARD_DIM + r, col) =
                    1 + (R + r * BOARD_DIM + col) % BOARD_SIZE;
    return res;
}

void debug_vuPrint(vu const &value) {
    for(UI i = 0; i < value.size(); i++)
        cout << value[i].toString() << ' ';
    cout << '\n';
}


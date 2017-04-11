#include "Sudoku.h"

int main() {
    Board const board = Board::debug_trivial();
    
    board.printBoard();
    debug_vuPrint(board.getRow(3));
    debug_vuPrint(board.getCol(4));
    debug_vuPrint(board.getBox(7));
    
}


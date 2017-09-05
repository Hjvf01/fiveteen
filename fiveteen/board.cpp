#include "board.h"


Board::Board(const QList<QList<int>> &_board) : board(_board) {
    assert(_board.size() == 4);
    for(int i = 0; i < _board.size(); i++)
        assert(_board[i].size() == 4);
}


Board::Board() {
    board = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15,  0}
    };
}


Board::~Board() {}


const QList<int>& Board::operator [](const unsigned int index) const {
    assert(index <= 3);
    return board[index];
}


string Board::str(void) const {
    string out;
    for(const QList<int>& row: board) {
        for(int elem: row) {
            if(elem < 10)
                out += " " + to_string(elem) + " ";
            else
                out += to_string(elem) + " ";
        }
        out += "\n";
    }

    return out;
}


void Board::swap(int left_row, int left_col, int right_row, int right_col) {
    int temp = board[left_row][left_col];
    board[left_row][left_col] = board[right_row][right_col];
    board[right_row][right_col] = temp;
}

#ifndef BOARD_H
#define BOARD_H


#include <iostream>
using std::cout;
using std::endl;
#include <ostream>
using std::ostream;
#include <cassert>
#include <string>
using std::string;
using std::to_string;


#include <QtCore/QList>


class Board {
    QList<QList<int>> board;

public:
    Board(const QList<QList<int>>& _board);
    Board();
    ~Board();

    const QList<int>& operator [] (const unsigned int index) const;


    string str(void) const;

    int height(void) const { return board.size(); }
    int width(void) const { return board[0].size(); }

    void swap(int left_row, int left_col, int right_row, int right_col);


    friend ostream& operator << (ostream& os, const Board& board) {
        return os << board.str();
    }


    friend bool operator == (const Board& left, const Board& right) {
        assert(left.board.size() == right.board.size());
        for(int i = 0; i < left.board.size(); ++i)
            assert(left[i].size() == right[i].size());

        int height = left.board.size();
        for(int row = 0; row < height; ++row) {
            int width = right.board[row].size();
            for(int col = 0; col < width; ++col) {
                if(left[row][col] != right[row][col])
                    return false;
            }
        }

        return true;
    }
};


#endif // BOARD_H

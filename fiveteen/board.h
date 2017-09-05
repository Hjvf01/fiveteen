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
    Board(const QList<QList<int>>& _board) : board(_board) {
        cout << __PRETTY_FUNCTION__ << endl;

        assert(_board.size() == 4);
        for(int i = 0; i < _board.size(); i++)
            assert(_board[i].size() == 4);
    }


    Board() {
        board = {
            { 1,  2,  3,  4},
            { 5,  6,  7,  8},
            { 9, 10, 11, 12},
            {13, 14, 15,  0}
        };
    }


    ~Board() {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    const QList<int>& operator [] (unsigned int index) const {
        assert(index <= 3);

        return board[index];
    }


    string str(void) const {
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

    int height(void) const { return board.size(); }
    int width(void) const { return board[0].size(); }


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


    friend ostream& operator << (ostream& os, const Board& board) {
        return os << board.str();
    }
};



#endif // BOARD_H

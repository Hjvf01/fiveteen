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
        assert(_board[0].size() == 4);
    }


    Board() = default;


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


    friend ostream& operator << (ostream& os, const Board& board) {
        return os << board.str();
    }
};



#endif // BOARD_H

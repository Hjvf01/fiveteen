#include <QCoreApplication>
#include <QtCore/QList>


#include "../../../fiveteen/board.h"


int main() {
    QList<QList<int>> _board = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15,  0},
    };

    Board board(_board);
    cout << board << endl;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

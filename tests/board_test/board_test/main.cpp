#include <cassert>

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

    Board final;
    cout << final;

    assert(final == board);
}

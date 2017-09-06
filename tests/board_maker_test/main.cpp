#include <QCoreApplication>

#include "../../fiveteen/board_maker.h"


int main() {
    QList<QList<int>> _board = make_board();
    qDebug() << _board;
    qDebug() << solvable(_board);

    return 0;
}

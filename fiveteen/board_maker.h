#ifndef BOARD_MAKER_H
#define BOARD_MAKER_H


#include <algorithm>
using std::shuffle;
using std::swap;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include <cassert>

#include <QtCore/QList>
#include <QtCore/QDebug>

QList<QList<int>> make_board(void);

int findRow(const QList<QList<int>>& board, int num);
int findCol(const QList<QList<int>>& board, int num);
int findAmount(const QList<QList<int>>& board, int num);

bool solvable(const QList<QList<int>>& board);


#endif // BOARD_MAKER_H

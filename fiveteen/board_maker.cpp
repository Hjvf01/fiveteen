#include "board_maker.h"


QList<QList<int>> make(mt19937& gen, uniform_int_distribution<int>& distrub) {
    QList<QList<int>> result = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15,  0},
    };

    shuffle(result.begin(), result.end(), gen);

    for(QList<int>& row: result)
        shuffle(row.begin(), row.end(), gen);

    for(int i = 0; i < 10; i++)
        swap(
            result[distrub(gen)][distrub(gen)],
            result[distrub(gen)][distrub(gen)]
        );

    return result;
}


QList<QList<int>> make_board() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrub(0, 3);

    auto result = make(gen, distrub);

    while(! solvable(result))
        result = make(gen, distrub);

    assert(solvable(result) == true);

    return result;
}


int findRow(const QList<QList<int>>& board, int num) {
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[i].size(); j++)
            if(board[i][j] == num)
                return i;

    return -1;
}

int findCol(const QList<QList<int> > &board, int num) {
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[i].size(); j++)
            if(board[i][j] == num)
                return j;

    return -1;
}


int findAmount(const QList<QList<int> > &board, int num) {
    int amount = 0;
    int num_row = findRow(board, num);

    for(int i = num_row; i < board.size(); i++) {
        if(i == num_row)
            for(int j = findCol(board, num); j < board[i].size(); j++)
                if(board[i][j] != 0 && board[i][j] < num)
                    ++amount;
        else
            for(int j = 0; j < board[i].size(); j++)
                if(board[i][j] != 0 && board[i][j] < num)
                    ++amount;
    }

    return amount;
}



bool solvable(const QList<QList<int>> &board) {
    /*
        https://ru.wikipedia.org/wiki/%D0%98%D0%B3%D1%80%D0%B0_%D0%B2_15
    */

    int sum = 0;
    int e = findRow(board, 0) + 1;

    assert(e != 0);

    for(int elem: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}) {
        sum += findAmount(board, elem) + e;
    }

    return ((sum % 2) == 0);
}

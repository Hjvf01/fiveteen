#ifndef BOARD_BUILDER_H
#define BOARD_BUILDER_H


#include <QQmlEngine>
#include <QQmlComponent>
#include <QUrl>
#include <QDebug>

#include "cell.h"
#include "board.h"


class BoardBuilder {
    QQmlComponent* cell;

public:
    BoardBuilder(QQmlEngine* engine);
    BoardBuilder();
    ~BoardBuilder();

    void setBuilder(QQmlEngine* engine);

    QList<Cell*> build(const Board& board) const;
};

#endif // BOARD_BUILDER_H

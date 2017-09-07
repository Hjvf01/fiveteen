#ifndef BOARD_BUILDER_H
#define BOARD_BUILDER_H


#include <QtQml/QQmlEngine>
#include <QtQml/QQmlComponent>
#include <QtCore/QUrl>
#include <QtCore/QDebug>

#include "../objects/cell.h"
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

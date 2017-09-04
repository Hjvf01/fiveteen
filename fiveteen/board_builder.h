#ifndef BOARD_BUILDER_H
#define BOARD_BUILDER_H


#include <QtQml/QQmlComponent>
#include <QtQml/QQmlEngine>


#include "board.h"
#include "cell.h"


class BoardBuilder {
    QQmlComponent* component;

public:
    BoardBuilder(QQmlEngine* engine) :
        component(new QQmlComponent(engine, QUrl("qrc:qml/cell.qml"))) {}

    QList<Cell*> build(const Board& board) {
        QList<Cell*> out;

        int height = 3;
        int width = 3;
        for(int i = 0; i <= height; i++) {
            for(int j = 0; j <= width; j++) {
                Cell* cell = dynamic_cast<Cell*>(component->create());
                cell->setNumber(board[i][j]);
                out.append(cell);
            }
        }
        return out;
    }

    ~BoardBuilder() {
        delete component;
    }
};


#endif // BOARD_BUILDER_H

#ifndef BOARD_BUILDER_H
#define BOARD_BUILDER_H


#include <QQmlEngine>
#include <QQmlComponent>
#include <QUrl>
#include <QDebug>

#include "cell.h"


class BoardBuilder {
    QQmlComponent* cell;

public:
    BoardBuilder(QQmlEngine* engine) {
        cell = new QQmlComponent(engine, QUrl("qrc:qml/cell.qml"));
    }

    BoardBuilder() { cell = nullptr; }

    ~BoardBuilder() {
        delete cell;
    }

    void setBuilder(QQmlEngine* engine) {
        cell = new QQmlComponent(engine, QUrl("qrc:qml/cell.qml"));
    }


    QList<Cell*> build(const Board& board) {
        if(cell == nullptr)
            throw "Cell didnt init";

        QList<Cell*> result;
        for(int i = 0; i < board.height(); i++) {
            for(int j = 0; j < board.width(); j++) {
                Cell* cell_obj = static_cast<Cell*>(cell->create());
                cell_obj->setNumber(board[i][j]);
                cell_obj->setX(j * CELL_SIZE);
                cell_obj->setY(i * CELL_SIZE);
                result.append(cell_obj);

                if(board[i][j] == 0)
                    cell_obj->setColor(QColor(0, 0, 0));
            }
        }

        return result;
    }
};

#endif // BOARD_BUILDER_H

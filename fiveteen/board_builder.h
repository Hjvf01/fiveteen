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

    ~BoardBuilder() {
        delete cell;
    }


    QList<Cell*> build(const Board& board) {
        QList<Cell*> result;
        for(int i = 0; i < board.height(); i++) {
            for(int j = 0; j < board.width(); j++) {
                Cell* cell_obj = dynamic_cast<Cell*>(cell->create());
                qDebug() << cell_obj;
                cell_obj->setNumber(board[i][j]);
                cell_obj->setX(j * cell_size);
                cell_obj->setY(i * cell_size);
                result.append(cell_obj);
            }
        }

        return result;
    }
};

#endif // BOARD_BUILDER_H

#include "board_builder.h"


BoardBuilder::BoardBuilder(QQmlEngine *engine) :
        cell(new QQmlComponent(engine, QUrl("qrc:qml/cell.qml"))) {}


BoardBuilder::BoardBuilder() : cell(nullptr) {}


BoardBuilder::~BoardBuilder() {
    delete cell;
}


void BoardBuilder::setBuilder(QQmlEngine *engine) {
    cell = new QQmlComponent(engine, QUrl("qrc:qml/cell.qml"));
}


QList<Cell*> BoardBuilder::build(const Board &board) const {
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
        }
    }

    return result;
}

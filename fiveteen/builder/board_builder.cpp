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
    assert(cell != nullptr);

    QList<Cell*> result;
    for(int i = 0; i < board.height(); i++) {
        for(int j = 0; j < board.width(); j++) {
            Cell* cell_obj = static_cast<Cell*>(cell->create());
            cell_obj->setNumber(board[i][j]);
            cell_obj->setX(j * Cell::getWidth());
            cell_obj->setY(i * Cell::getHeight());
            result.append(cell_obj);
        }
    }
    return result;
}

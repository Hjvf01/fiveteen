#include "cell.h"


Cell::Cell(QQuickItem *parent) :
        QQuickPaintedItem(parent),
        number("0"),
        color(QColor(255, 175, 0))
{
    cell.setWidth(CELL_SIZE);
    cell.setHeight(CELL_SIZE);

    setWidth(CELL_SIZE);
    setHeight(CELL_SIZE);
}


Cell::~Cell() {}


void Cell::paint(QPainter *painter) {
    if(number != "0") {
        painter->setBrush(QBrush(color));
        painter->drawRect(cell);

        painter->setBrush(QBrush(Qt::black));
        QFont font = painter->font();
        font.setPixelSize(CELL_SIZE - 15);
        painter->setFont(font);
        painter->drawText(cell, Qt::AlignCenter, number);
    }
}

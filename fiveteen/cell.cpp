#include "cell.h"


int Cell::cell_size = 120;
QRect Cell::cell = QRect();


Cell::Cell(QQuickItem *parent) :
        QQuickPaintedItem(parent),
        number("0"),
        color(QColor(255, 175, 0))
{
    cell.setWidth(cell_size);
    cell.setHeight(cell_size);

    setWidth(cell_size);
    setHeight(cell_size);
}


Cell::~Cell() {}


void Cell::paint(QPainter *painter) {
    if(number != "0") {
        painter->setBrush(QBrush(color));
        painter->drawRect(cell);

        painter->setBrush(QBrush(Qt::black));
        QFont font = painter->font();
        font.setPixelSize(cell_size - 15);
        painter->setFont(font);
        painter->drawText(cell, Qt::AlignCenter, number);
    }
}

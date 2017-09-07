#include "cell.h"


int Cell::cell_width = 120;
int Cell::cell_height = 120;
QRect Cell::cell = QRect();


Cell::Cell(QQuickItem *parent) :
        QQuickPaintedItem(parent),
        number("0"),
        color(QColor(245, 245, 240))
{
    cell.setWidth(120);
    cell.setHeight(120);

    setWidth(120);
    setHeight(120);
}


Cell::~Cell() {}


void Cell::paint(QPainter *painter) {
    int font_size = cell_width < cell_height ? cell_width : cell_height;

    if(number != "0") {
        painter->setBrush(QBrush(color));
        painter->drawRect(cell);

        painter->setBrush(QBrush(Qt::black));
        QFont font = painter->font();
        font.setPixelSize(font_size - 20);
        painter->setFont(font);
        painter->drawText(cell, Qt::AlignCenter, number);
    }
}

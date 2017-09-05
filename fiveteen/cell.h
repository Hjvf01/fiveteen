#ifndef CELL_H
#define CELL_H


#include <iostream>
using std::cout;
using std::endl;


#include <QtCore/QRect>
#include <QtGui/QBrush>
#include <QtGui/QPainter>
#include <QtQuick/QQuickPaintedItem>


static const int cell_size = 120;   //px


class Cell : public QQuickPaintedItem {
    QRect cell;
    QString number;

public:
    Cell(QQuickItem* parent = nullptr) : QQuickPaintedItem(parent) {
        cell.setWidth(cell_size);
        cell.setHeight(cell_size);

        setWidth(cell_size);
        setHeight(cell_size);

        number = "0";
    }

    ~Cell() override {}


    void setNumber(int _number) {
        number = QString::number(_number);
    }

    QString getNumber(void) const {
        return number;
    }

    void paint(QPainter *painter) override {
        cout << __PRETTY_FUNCTION__ << endl;

        painter->setBrush(QBrush(Qt::cyan));
        painter->drawRect(cell);

        painter->setBrush(QBrush(Qt::black));
        QFont font = painter->font();
        font.setPixelSize(cell_size - 15);
        painter->setFont(font);
        painter->drawText(cell, Qt::AlignCenter, number);
    }
};


#endif // CELL_H

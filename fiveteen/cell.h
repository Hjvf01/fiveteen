#ifndef CELL_H
#define CELL_H


#include <iostream>
using std::cout;
using std::endl;


#include <QtCore/QRect>
#include <QtGui/QBrush>
#include <QtGui/QColor>
#include <QtGui/QPainter>
#include <QtQuick/QQuickPaintedItem>


static const int CELL_SIZE = 120;   //px


class Cell : public QQuickPaintedItem {
    QRect cell;
    QString number;
    QColor color;

public:
    Cell(QQuickItem* parent = nullptr) :
            QQuickPaintedItem(parent),
            color(QColor(255, 175, 0))
    {
        cell.setWidth(CELL_SIZE);
        cell.setHeight(CELL_SIZE);

        setWidth(CELL_SIZE);
        setHeight(CELL_SIZE);

        number = "0";
    }

    ~Cell() override {}


    void setNumber(int _number) {
        number = QString::number(_number);
    }

    void setColor(const QColor& _color) {
        color = _color;
    }

    QString getNumber(void) const {
        return number;
    }

    bool isNull(void) const { return number == "0"; }

    void paint(QPainter *painter) override {
        cout << __PRETTY_FUNCTION__ << endl;

        painter->setBrush(QBrush(color));
        painter->drawRect(cell);

        if(number != "0") {
            painter->setBrush(QBrush(Qt::black));
            QFont font = painter->font();
            font.setPixelSize(CELL_SIZE - 15);
            painter->setFont(font);
            painter->drawText(cell, Qt::AlignCenter, number);
        }
    }

    QRect cellRect(void) const {
        return QRect(x(), y(), CELL_SIZE, CELL_SIZE);
    }
};


#endif // CELL_H

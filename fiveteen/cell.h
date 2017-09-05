#ifndef CELL_H
#define CELL_H


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
    Cell(QQuickItem* parent = nullptr);
    ~Cell() override;


    void setNumber(int _number) { number = QString::number(_number); }
    void setColor(const QColor& _color) { color = _color; }

    QString getNumber(void) const { return number; }
    bool isNull(void) const { return number == "0"; }
    QRect cellRect(void) const {
        return QRect(
            x(), y(), CELL_SIZE, CELL_SIZE
        );
    }

    void paint(QPainter *painter) override;
};


#endif // CELL_H

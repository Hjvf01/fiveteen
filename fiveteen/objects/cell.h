#ifndef CELL_H
#define CELL_H


#include <QtCore/QRect>
#include <QtGui/QBrush>
#include <QtGui/QColor>
#include <QtGui/QPainter>
#include <QtQuick/QQuickPaintedItem>


class Cell : public QQuickPaintedItem {
    static int cell_size;
    static QRect cell;

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
            x(), y(), cell_size, cell_size
        );
    }

    static int getSize(void) { return cell_size; }

    static void setSize(int size) {
        cell_size = size;
        cell.setWidth(size);
        cell.setHeight(size);
    }

    void paint(QPainter *painter) override;
};


#endif // CELL_H

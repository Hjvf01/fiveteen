#ifndef CELL_H
#define CELL_H


#include <QtCore/QRect>
#include <QtGui/QBrush>
#include <QtGui/QColor>
#include <QtGui/QPainter>
#include <QtQuick/QQuickPaintedItem>


class Cell : public QQuickPaintedItem {
    static int cell_height;
    static int cell_width;
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
            x(), y(), cell_width, cell_height
        );
    }

    static int getHeight(void) { return cell_height; }
    static int getWidth(void) { return cell_width; }

    static void _setHeight(int h) {
        cell_height = h;
        cell.setHeight(h);
    }

    static void _setWidth(int w) {
        cell_width = w;
        cell.setWidth(w);
    }

    void paint(QPainter *painter) override;
};


#endif // CELL_H

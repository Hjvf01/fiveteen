#ifndef BOARD_CONTROL_H
#define BOARD_CONTROL_H


#include <QObject>


class BoardControl : public QObject {
    Q_OBJECT

    Q_PROPERTY(int height READ getHeight WRITE setHeight)
    Q_PROPERTY(int width READ getWidth WRITE setWidth)

    int _height = 480;
    int _width = 480;

public:
    int getHeight(void) const { return _height; }
    int getWidth(void) const { return _width; }

    void setHeight(int h) { _height = h; }
    void setWidth(int w) { _width = w; }

signals:
    void sizeChanged(int s);

    void scaleWidth(void);
    void scaleHeight(void);
};

#endif // BOARD_CONTROL_H

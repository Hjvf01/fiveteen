#ifndef BOARD_CONTROL_H
#define BOARD_CONTROL_H


#include <QObject>


class BoardControl : public QObject {
    Q_OBJECT

    Q_PROPERTY(int size READ getSize WRITE setSize NOTIFY sizeChanged)

    int _size = 480;

public:
    int getSize(void) { return _size; }
    void setSize(int s) { _size = s; }

signals:
    void sizeChanged(int s);

    void scale(void);
};

#endif // BOARD_CONTROL_H

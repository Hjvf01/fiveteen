#ifndef CELL_CONTROL_H
#define CELL_CONTROL_H


#include <QObject>


class CellControl : public QObject {
    Q_OBJECT

    Q_PROPERTY(int duration READ getDuration)
    Q_PROPERTY(int step READ getStep)

    const int _duration = 20;
    const int _step = 120;

signals:
    void moveUp(void);
    void moveLeft(void);
    void moveDown(void);
    void moveRight(void);

    void select(void);
    void unSelect(void);

public:
    int getDuration(void) const { return _duration; }
    int getStep(void) const { return _step; }
};


#endif // CELL_CONTROL_H

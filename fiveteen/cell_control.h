#ifndef CELL_CONTROL_H
#define CELL_CONTROL_H


#include <QObject>


class CellControl : public QObject {
    Q_OBJECT

    Q_PROPERTY(
        int duration
        READ getDuration
        WRITE setDuration
        NOTIFY durationChanged
    )

    Q_PROPERTY(int step READ getStep)

    int _duration = 200;
    const int _step = 120;

signals:
    void moveUp(void);
    void moveLeft(void);
    void moveDown(void);
    void moveRight(void);

    void select(void);
    void unSelect(void);

    void durationChanged(int d);

public:
    int getDuration(void) const { return _duration; }
    int getStep(void) const { return _step; }

    void setDuration(int d) { _duration = d; }
};


#endif // CELL_CONTROL_H

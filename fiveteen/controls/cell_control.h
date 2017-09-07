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

    Q_PROPERTY(int step READ getStep WRITE setStep)

    static int _duration;
    static int _step;

signals:
    void moveUp(void);
    void moveLeft(void);
    void moveDown(void);
    void moveRight(void);

    void scale(void);

    void durationChanged(int d);

public:
    static int getDuration(void) { return _duration; }
    static int getStep(void) { return _step; }

    static void setStep(int s) { _step = s; }
    static void setDuration(int d) { _duration = d; }
};

#endif // CELL_CONTROL_H

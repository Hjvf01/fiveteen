#ifndef CELL_CONTROL_H
#define CELL_CONTROL_H


#include <QObject>


class CellControl : public QObject {
    Q_OBJECT

    Q_PROPERTY(
        int durationX
        READ getDurationX
        WRITE setDurationX
        NOTIFY durationXChanged
    )

    Q_PROPERTY(
        int durationY
        READ getDurationY
        WRITE setDurationX
        NOTIFY durationYChanged
    )

    Q_PROPERTY(int stepX READ getStepX WRITE setStepX)
    Q_PROPERTY(int stepY READ getStepY WRITE setStepY)

    static int durationX;
    static int durationY;
    static int stepX;
    static int stepY;

signals:
    void moveUp(void);
    void moveLeft(void);
    void moveDown(void);
    void moveRight(void);

    void scaleHeight(void);
    void scaleWidth(void);

    void durationXChanged(int d);
    void durationYChanged(int d);

public:
    static int getDurationX(void) { return durationX; }
    static int getDurationY(void) { return durationY; }
    static int getStepX(void) { return stepX; }
    static int getStepY(void) { return stepY; }

    static void setStepX(int s) { stepX = s; }
    static void setStepY(int s) { stepY = s; }
    static void setDurationX(int d) { durationX = d; }
    static void setDurationY(int d) { durationY = d; }
};

#endif // CELL_CONTROL_H

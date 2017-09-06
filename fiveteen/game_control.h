#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H


#include <QtCore/QObject>

class GameControl : public QObject {
    Q_OBJECT

    Q_PROPERTY(int turn READ getTurns WRITE setTurns NOTIFY turnChanged)

    int _height = 480;
    int _width = 640;

    int turn = 0;

public:
    int getTurns(void) const { return turn; }

    void setTurns(int t) { turn = t; }

signals:
    void finish(int amount);

    void turnChanged(int t);
};


#endif // GAME_CONTROL_H

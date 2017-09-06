#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H


#include <QtCore/QObject>

class GameControl : public QObject {
    Q_OBJECT

    int _height = 480;
    int _width = 640;

signals:
    void finish(int amount);
};


#endif // GAME_CONTROL_H

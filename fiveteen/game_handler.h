#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H


#include <QObject>
#include <QQuickView>
#include <QQuickItem>
#include <QQmlEngine>

#include "board.h"
#include "board_builder.h"


class GameHandler : public QObject {
    QQuickView* view;
    QQuickItem* root;
    QQmlEngine* engine;

    Board board;

public:
    GameHandler(QQuickView* _view) : QObject(),
            view(_view), root(view->rootObject()), engine(view->engine())
    {}
};


#endif // GAME_HANDLER_H

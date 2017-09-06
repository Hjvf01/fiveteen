#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H


#include <ostream>
using std::ostream;


#include <QObject>
#include <QQuickView>
#include <QQuickItem>
#include <QQmlEngine>
#include <QPoint>

#include "board.h"
#include "board_builder.h"
#include "cell_control.h"
#include "game_control.h"
#include "cell.h"
#include "board_maker.h"


enum class Direction {
    stop = 0,
    up = 1,
    left = 2,
    down = 3,
    right = 4
};


class BoardHandler : public QObject {
    Q_OBJECT

    QQuickView* view;
    QQuickItem* root;
    QQmlEngine* engine;

    Board board;
    Board final;
    BoardBuilder builder;

    QList<Cell*> cells;

public:
    BoardHandler(QQuickView* _view);
    ~BoardHandler() override;

    void init(void);

    Direction getDirection(const QString& num) const;

    Cell* findCell(const QPoint& point) const;
    Cell* getZero(void) const;

    void swap(Cell* selected, Cell* zero);

    bool finish(void);

private:
    int findRow(int number) const;
    int findCol(int number) const;
};


class GameHandler : public QObject {
    Q_OBJECT

    int amount;

    QQuickView* view;
    BoardHandler* board;
    GameControl* main_control;

    Cell* zero = nullptr;

public:
    GameHandler(QQuickView* _view);
    ~GameHandler() override;

    void initBoard(void);

public slots:
    void onMouseClicked(int x, int y);

private:
    void move(Cell* selected);
};


#endif // GAME_HANDLER_H

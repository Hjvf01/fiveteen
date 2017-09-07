#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H


#include <ostream>
using std::ostream;


#include <QObject>
#include <QQuickView>
#include <QQuickItem>
#include <QQmlEngine>
#include <QPoint>

#include "builder/board.h"
#include "builder/board_maker.h"
#include "builder/board_builder.h"
#include "controls/cell_control.h"
#include "controls/game_control.h"
#include "controls/board_control.h"
#include "objects/cell.h"


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

    BoardControl* control;

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
    void clear(void);

    bool finish(void);

private:
    int findRow(int number) const;
    int findCol(int number) const;
    int smallestSize(int s) const;
    void scale(void);

private slots:
    void onHeightChange(int);
    void onWidthChange(int);
};


class GameHandler : public QObject {
    Q_OBJECT

    int amount;

    QQuickView* view;
    BoardHandler* board;
    GameControl* main_control;
    QQuickItem* game_board;

    Cell* zero = nullptr;

public:
    GameHandler(QQuickView* _view);
    ~GameHandler() override;

    void initBoard(void);

public slots:
    void onMouseClicked(int x, int y);
    void onRestart(void);

private:
    void move(Cell* selected);
};


#endif // GAME_HANDLER_H

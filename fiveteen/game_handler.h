#ifndef GAME_HANDLER_H
#define GAME_HANDLER_H


#include <QObject>
#include <QQuickView>
#include <QQuickItem>
#include <QQmlEngine>
#include <QPoint>

#include "board.h"
#include "board_builder.h"
#include "cell_control.h"
#include "cell.h"


class GameHandler : public QObject {
    Q_OBJECT

    QQuickView* view;
    QQuickItem* root;
    QQmlEngine* engine;

    Board board;
    BoardBuilder builder;

    Cell* selected = nullptr;
    QList<Cell*> cells;

public:
    GameHandler(QQuickView* _view);
    ~GameHandler() override;

    void initBoard(void);

public slots:
    void onMouseClicked(int x, int y);

private:
    Cell* findCell(const QPoint& point) const;
    void move(CellControl* control);
};


#endif // GAME_HANDLER_H

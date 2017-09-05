#include "game_handler.h"


GameHandler::GameHandler(QQuickView *_view) :
        QObject(),
        view(_view),
        board(new BoardHandler(_view))
{
    connect(
        view->rootObject(), SIGNAL(mouseClicked(int, int)),
        this, SLOT(onMouseClicked(int,int))
    );
}


GameHandler::~GameHandler() {
    delete board;
}


void GameHandler::initBoard(void) {
    board->init();
    zero = board->getZero();
    zero->findChild<CellControl*>("control")->setDuration(0);
}


void GameHandler::onMouseClicked(int x, int y) {
    Cell* selected = board->findCell(QPoint(x, y));
    assert(selected != nullptr);
    move(selected);
}


void GameHandler::move(Cell* selected) {
    CellControl* control = selected->findChild<CellControl*>("control");
    CellControl* zero_control = zero->findChild<CellControl*>("control");

    assert(control != nullptr);
    assert(zero != nullptr);
    assert(zero_control != nullptr);

    auto direction = board->getDirection(selected->getNumber());
    switch(direction) {
    case Direction::up:
        board->swap(selected, zero);
        emit control->moveUp();
        emit zero_control->moveDown();
        break;
    case Direction::left:
        board->swap(selected, zero);
        emit control->moveLeft();
        emit zero_control->moveRight();
        break;
    case Direction::down:
        board->swap(selected, zero);
        emit control->moveDown();
        emit zero_control->moveUp();
        break;
    case Direction::right:
        board->swap(selected, zero);
        emit control->moveRight();
        emit zero_control->moveLeft();
        break;
    default:
        return;
    }
}
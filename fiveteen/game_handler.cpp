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
    qDebug() << x << "\t" << y;

    Cell* selected = board->findCell(QPoint(x, y));
    if(selected != nullptr) {
        qDebug() << selected->getNumber();
        qDebug() << selected->cellRect();
        move(selected);
    } else {
        qDebug() << "didt find";
    }
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
        //board->swap(selected);
        emit control->moveUp();
        emit zero_control->moveDown();
        break;
    case Direction::left:
        //board->swap(selected);
        emit control->moveLeft();
        emit zero_control->moveRight();
        break;
    case Direction::down:
        //board->swap(selected);
        emit control->moveDown();
        emit zero_control->moveUp();
        break;
    case Direction::right:
        //board->swap(selected);
        emit control->moveRight();
        emit control->moveLeft();
        break;
    default:
        return;
    }
}

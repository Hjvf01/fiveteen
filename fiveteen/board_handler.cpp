#include "game_handler.h"


BoardHandler::BoardHandler(QQuickView *_view) :
        QObject(),
        view(_view),
        root(view->rootObject()),
        engine(view->engine())
{
    builder.setBuilder(engine);
}


BoardHandler::~BoardHandler() {
    for(Cell* cell: cells)
        delete cell;
}


void BoardHandler::init() {
    cells = builder.build(board);

    for(Cell* cell: cells) {
        cell->setParentItem(root);
        cell->setParent(view);
    }
}


Cell* BoardHandler::findCell(const QPoint &point) const {
    for(Cell* cell: cells)
        if(cell->cellRect().contains(point))
            return cell;

    return nullptr;
}


Direction BoardHandler::getDirection(const QString& num) const {
    int number = num.toInt();
    int row = findRow(number);
    int col = findCol(number);

    assert(row != -1);
    assert(col != -1);

    Direction result = Direction::stop;
    if(row != 0 && board[row - 1][col] == 0)
        result = Direction::up;
    else if(col != board.width() - 1 && board[row][col + 1] == 0)
        result = Direction::left;
    else if(row != board.height() - 1 && board[row + 1][col] == 0)
        return Direction::down;
    else if(col != 0 && board[row][col - 1] == 0)
        result = Direction::right;

    return result;
}


int BoardHandler::findRow(int number) const {
    int height = board.height();
    int width = board.width();

    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
            if(number == board[i][j])
                return i;

    return -1;
}


int BoardHandler::findCol(int number) const {
    int height = board.height();
    int width = board.width();

    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
            if(number == board[i][j])
                return j;

    return -1;
}


Cell* BoardHandler::getZero() const {
    int index = 0;
    for(int i = 0; i < cells.size(); i++)
        if(cells[i]->getNumber() == "0") {
            index = i;
            break;
        }

    return cells[index];
}


void BoardHandler::swap(Cell *selected, Cell *zero) {
    int selected_row = findRow(selected->getNumber().toInt()),
        selected_col = findCol(selected->getNumber().toInt());

    int zero_row = findRow(zero->getNumber().toInt()),
        zero_col = findCol(zero->getNumber().toInt());

    board.swap(
        selected_row, selected_col,
        zero_row, zero_col
    );
}


ostream& operator << (ostream& os, const Direction& dir) {
    switch(dir) {
        case Direction::stop: return os << "stop";
        case Direction::up: return os << "up";
        case Direction::left: return os << "left";
        default: return os << "right";
    }
}

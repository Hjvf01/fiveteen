#include "handlers.h"


BoardHandler::BoardHandler(QQuickView *_view) :
        QObject(),
        view(_view),
        root(view->rootObject()),
        engine(view->engine()),
        control(root->findChild<BoardControl*>("boardControl")),
        board(Board(make_board()))
{
    assert(control != nullptr);
    assert(root != nullptr);
    assert(engine != nullptr);

    builder.setBuilder(engine);
    connect(
        view, &QQuickView::heightChanged, this, &BoardHandler::onHeightChange
    );
    connect(
        view, &QQuickView::widthChanged, this, &BoardHandler::onWidthChange
    );
}


BoardHandler::~BoardHandler() {
    for(Cell* cell: cells) delete cell;
}


void BoardHandler::clear() {
    for(Cell* cell: cells) {
        delete cell;
    }
    cells.clear();
    board = Board(make_board());

    assert(cells.size() == 0);
}


void BoardHandler::init() {
    cells = builder.build(board);

    for(Cell* cell: cells) {
        cell->_setWidth(control->getWidth() / 4);
        cell->_setHeight(control->getHeight() / 4);
        cell->setWidth(control->getWidth() / 4);
        cell->setHeight(control->getHeight() / 4);
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


bool BoardHandler::finish(void) {
    return board == final;
}


int BoardHandler::smallestSize(int size) const {
    while(size % 4 != 0)
        size--;
    assert((size % 4) == 0);
    return size;
}


void BoardHandler::onHeightChange(int) {
    int size = smallestSize(view->height());
    control->setHeight(size);

    Cell::_setHeight(size / 4);
    CellControl::setStepY(size / 4);

    for(Cell* cell: cells) {
        CellControl* _control = cell->findChild<CellControl*>("control");
        assert(_control != nullptr);

        emit _control->scaleHeight();

        cell->setX(findCol(cell->getNumber().toInt()) * Cell::getWidth());
        cell->setY(findRow(cell->getNumber().toInt()) * Cell::getHeight());
    }

    emit control->scaleHeight();
}


void BoardHandler::onWidthChange(int) {
    int size = smallestSize(view->width());
    control->setWidth(size);

    Cell::_setWidth(size / 4);
    CellControl::setStepX(size / 4);

    for(Cell* cell: cells) {
        CellControl* _control = cell->findChild<CellControl*>("control");
        assert(_control != nullptr);

        emit _control->scaleWidth();

        cell->setX(findCol(cell->getNumber().toInt()) * Cell::getWidth());
        cell->setY(findRow(cell->getNumber().toInt()) * Cell::getHeight());
    }

    emit control->scaleWidth();
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

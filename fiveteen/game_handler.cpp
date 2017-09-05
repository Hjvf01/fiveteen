#include "game_handler.h"


GameHandler::GameHandler(QQuickView *_view) : QObject() {
    view = _view;
    root = _view->rootObject();
    engine = _view->engine();

    builder.setBuilder(engine);

    connect(
        root, SIGNAL(mouseClicked(int, int)),
        this, SLOT(onMouseClicked(int,int))
    );
}


GameHandler::~GameHandler() {
    delete root;
    delete engine;

    for(Cell* c: cells) delete c;
}


void GameHandler::initBoard(void) {
    cells = builder.build(board);

    for(Cell* cell: cells) {
        cell->setParentItem(root);
        cell->setParent(view);
    }
}


void GameHandler::onMouseClicked(int x, int y) {
    qDebug() << x << "\t" << y;

    selected = findCell(QPoint(x, y));
    if(selected != nullptr) {
        qDebug() << selected->getNumber();
        qDebug() << selected->cellRect();
        CellControl* cell_control =
                selected->findChild<CellControl*>("control");
        move(cell_control);
    } else {
        qDebug() << "didt find";
    }
}


Cell* GameHandler::findCell(const QPoint &point) const {
    for(Cell* cell: cells) {
        if(cell->cellRect().contains(point) && ! cell->isNull())
            return cell;
    }

    return nullptr;
}


void GameHandler::move(CellControl *control) {
    //
}

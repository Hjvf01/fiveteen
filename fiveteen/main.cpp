#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlEngine>


#include "cell.h"
#include "board.h"
#include "board_builder.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Cell>("Cells", 1, 0, "Cell");

    QQuickView view;
    view.setSource(QUrl("qrc:qml/main.qml"));
    view.show();

    QQmlEngine* engine = view.engine();
    QQuickItem* root = view.rootObject();

    QQmlComponent cell_compenent(engine, QUrl("qrc:qml/cell.qml"));
    Cell* cell = dynamic_cast<Cell*>(cell_compenent.create());
    cell->setParentItem(root);
    cell->setParent(&view);
    cell->setX(10);
    cell->setY(10);

    QList<QList<int>> _board = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15,  0},
    };

    Board board(_board);
    BoardBuilder builder(engine);
    QList<Cell*> cells = builder.build(board);
    qDebug() << cells.size();
    for(Cell* cell: cells) {
        cell->setParentItem(root);
        cell->setParent(&view);
    }

    return app.exec();
}

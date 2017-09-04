#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>


#include "../../fiveteen/board_builder.h"
#include "../../fiveteen/cell.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Cell*>("Cells", 1, 0, "Cell");

    QQuickView view;
    view.setSource(QUrl("qrc:qml/main.qml"));
    view.show();

    QList<QList<int>> _board = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15,  0},
    };

    BoardBuilder builder(view.engine());
    Board board(_board);
    QList<Cell*> cells = builder.build(board);
    for(Cell* cell: cells)
        cout << cell << endl;

    return app.exec();
}

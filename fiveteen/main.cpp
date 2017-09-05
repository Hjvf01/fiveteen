#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlEngine>


#include "cell.h"
#include "board.h"
#include "board_builder.h"
#include "game_handler.h"
#include "cell_control.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Cell>("Cells", 1, 0, "Cell");
    qmlRegisterType<CellControl>("Controls", 1, 0, "CellControl");

    QQuickView view;
    view.setSource(QUrl("qrc:qml/main.qml"));
    view.setX(55);
    view.setY(55);
    view.show();

    GameHandler handler(&view);
    handler.initBoard();

    return app.exec();
}

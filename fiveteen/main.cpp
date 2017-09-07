#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include "handlers/handlers.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Cell>("Cells", 1, 0, "Cell");
    qmlRegisterType<CellControl>("Controls", 1, 0, "CellControl");
    qmlRegisterType<BoardControl>("Controls", 1, 0, "BoardControl");
    qmlRegisterType<GameControl>("Controls", 1, 0, "GameControl");

    QQuickView view;
    view.setSource(QUrl("qrc:qml/main.qml"));
    view.setX(55);
    view.setY(55);
    view.show();

    QObject::connect(
        view.engine(), SIGNAL(quit()),
        QCoreApplication::instance(), SLOT(quit())
    );

    GameHandler handler(&view);
    handler.initBoard();

    return app.exec();
}

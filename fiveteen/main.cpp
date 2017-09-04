#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>


#include "cell.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    qmlRegisterType<Cell>("Cells", 1, 0, "Cell");

    QQuickView view;
    view.setSource(QUrl("qrc:qml/main.qml"));
    view.show();

    return app.exec();
}

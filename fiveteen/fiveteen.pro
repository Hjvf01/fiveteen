TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp\
    builder/board.cpp\
    builder/board_builder.cpp\
    builder/board_maker.cpp\
    #
    controls/cell_control.cpp\
    #
    handlers/game_handler.cpp\
    handlers/board_handler.cpp\
    #
    objects/cell.cpp\

HEADERS +=\
    builder/board.h\
    builder/board_builder.h\
    builder/board_maker.h\
    #
    controls/board_control.h\
    controls/cell_control.h\
    controls/game_control.h\
    #
    objects/cell.h\
    handlers/handlers.h

RESOURCES += qml.qrc

QML_IMPORT_PATH =

QML_DESIGNER_IMPORT_PATH =

DEFINES += QT_DEPRECATED_WARNINGS

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

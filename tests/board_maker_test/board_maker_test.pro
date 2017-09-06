QT += core
QT -= gui

CONFIG += c++11

TARGET = board_maker_test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=\
    main.cpp\
    ../../fiveteen/board_maker.cpp

HEADERS +=\
    ../../fiveteen/board_maker.h

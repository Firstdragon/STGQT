#-------------------------------------------------
#
# Project created by QtCreator 2015-08-13T18:35:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = STGQT
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    Map.cpp \
    Bot.cpp \
    GameEngine.cpp \
    Player.cpp \
    Visual.cpp

HEADERS  += window.h \
    Map.h \
    Bot.h \
    GameEngine.h \
    Player.h \
    Visual.h

FORMS    += window.ui

DISTFILES +=

RESOURCES += \
    images.qrc

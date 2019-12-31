#-------------------------------------------------
#
# Project created by QtCreator 2019-12-31T08:13:45
#
#-------------------------------------------------

QT       += core gui
CONFIG +=C++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BallGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    leftwidget.cpp \
    rightwidget.cpp \
    ball.cpp \
    paintlabel.cpp

HEADERS  += mainwindow.h \
    leftwidget.h \
    rightwidget.h \
    ball.h \
    paintlabel.h

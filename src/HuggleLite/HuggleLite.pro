#-------------------------------------------------
#
# Project created by QtCreator 2018-02-08T03:55:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HuggleLite
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    resources.cpp \
    queue.cpp

HEADERS  += mainwindow.hpp \
    definitions.hpp \
    login.hpp \
    resources.hpp \
    queue.hpp

FORMS    += mainwindow.ui \
    login.ui

#-------------------------------------------------
#
# Project created by QtCreator 2013-04-22T11:38:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hw5-2
TEMPLATE = app


SOURCES += main.cpp\
        filecreator.cpp \
    creationThread.cpp

HEADERS  += filecreator.h \
    ../creationThread.h \
    creationThread.h

FORMS    += filecreator.ui

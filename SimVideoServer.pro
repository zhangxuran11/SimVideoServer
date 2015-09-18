#-------------------------------------------------
#
# Project created by QtCreator 2015-09-02T19:32:59
#
#-------------------------------------------------

QT       += core gui network

TARGET = SimVideoServer
TEMPLATE = app
include(ZTPManager/ZTPManager.pri)

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

include(../defaults.pri)

QT += core gui widgets

TEMPLATE = lib
TARGET = todolibrary

SOURCES += mainwindow.cpp \
           task.cpp

HEADERS += mainwindow.h \
           task.h

FORMS   += mainwindow.ui \
           task.ui

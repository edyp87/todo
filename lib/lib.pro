include(../defaults.pri)

QT += core gui widgets

TEMPLATE = lib
TARGET = todolibrary

SOURCES += mainwindow.cpp \
    TaskUI.cpp \
    Task.cpp \
    TaskManager.cpp

HEADERS += mainwindow.h \
    TaskUI.h \
    Task.h \
    TaskManager.h

FORMS   += mainwindow.ui \
           task.ui

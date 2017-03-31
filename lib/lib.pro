include(../defaults.pri)

QT += core gui widgets

TEMPLATE = lib
TARGET = todolibrary

SOURCES += \
    Task.cpp \
    TaskManager.cpp \
    TaskUI.cpp \
    TaskManagerUI.cpp

HEADERS += \
    Task.h \
    TaskManager.h \
    TaskUI.h \
    TaskManagerUI.h

FORMS   += mainwindow.ui \
           task.ui

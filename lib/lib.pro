include(../defaults.pri)

QT += core gui widgets

TEMPLATE = lib
TARGET = todolibrary

SOURCES += \
    TaskUI.cpp \
    Task.cpp \
    TaskManager.cpp \
    TaskManagerUI.cpp \
    TaskUI2.cpp \
    TaskManagerUI2.cpp

HEADERS += \
    TaskUI.h \
    Task.h \
    TaskManager.h \
    TaskManagerUI.h \
    TaskUI2.h \
    TaskManagerUI2.h

FORMS   += mainwindow.ui \
           task.ui

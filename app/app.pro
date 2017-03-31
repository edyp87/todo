include(../defaults.pri)

QT += core gui widgets

TEMPLATE = app

LIBS += -L../lib -L../lib/debug -ltodolibrary

SOURCES += main.cpp


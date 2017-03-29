include(../defaults.pri)

QT += testlib

TEMPLATE = app

LIBS += -L../lib -ltodolibrary -lgmock -pthread

SOURCES += \
    TaskUT.cpp

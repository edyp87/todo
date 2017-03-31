include(../defaults.pri)

QT += testlib

TEMPLATE = app

LIBS += -L../lib -L../lib/debug -ltodolibrary

SOURCES += \
    TaskUT.cpp \
    TaskManagerUT.cpp \
    main.cpp

HEADERS += \
    TaskUT.h \
    TestRunner.h \
    TaskManagerUT.h

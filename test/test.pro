include(../defaults.pri)

QT += testlib

TEMPLATE = app

LIBS += -L../lib -ltodolibrary -lgmock -pthread

SOURCES += \
    TaskUT.cpp \
    TaskManagerUT.cpp \
    main.cpp

HEADERS += \
    TaskUT.h \
    TestRunner.h \
    TaskManagerUT.h

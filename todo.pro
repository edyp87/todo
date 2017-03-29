TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = \
    lib \
    app \
    test

lib.depends = src
tests.depends = src

OTHER_FILES += \
    defaults.pri


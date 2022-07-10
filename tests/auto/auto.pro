include(gtest_dependency.pri)

QT += core websockets

CONFIG += console
CONFIG -= app_bundle
CONFIG += thread

include(../../src/src.pri)

SOURCES += \
        src/main.cpp \
        src/IrcMessages.cpp \
        src/tst_testno1.cpp

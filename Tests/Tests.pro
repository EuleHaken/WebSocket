include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread

CONFIG += c++20

SOURCES += \
        main.cpp         tst_testno1.cpp

include(lib/WebSocket.pri)

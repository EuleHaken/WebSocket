include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread

CONFIG += c++20

SOURCES += \
        src/IrcMessages.cpp \
        src/main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../WebSocket/release/ -lWebSocket
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../WebSocket/debug/ -lWebSocket

INCLUDEPATH += $$PWD/../WebSocket
DEPENDPATH += $$PWD/../WebSocket

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../WebSocket/release/libWebSocket.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../WebSocket/debug/libWebSocket.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../WebSocket/release/WebSocket.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../WebSocket/debug/WebSocket.lib

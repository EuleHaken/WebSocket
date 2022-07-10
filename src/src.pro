QT += core websockets

TEMPLATE = lib
CONFIG += staticlib

INCDIR = $$PWD/../include

DEPENDPATH += $$PWD $$INCDIR
INCLUDEPATH += $$PWD $$INCDIR

HEADERS += \
    $$INCDIR/WebSocket_global.hpp \
    $$INCDIR/WebSocket.hpp \
    $$INCDIR/IrcMessage.hpp \
    $$INCDIR/CommandHandler.hpp \
    $$INCDIR/PrivmsgMessage.hpp \
    $$INCDIR/UsernoticeMessage.hpp \
    $$INCDIR/ClearchatMessage.hpp

SOURCES += \
    $$PWD/WebSocket.cpp \
    $$PWD/IrcMessage.cpp \
    $$PWD/PrivmsgMessage.cpp \
    $$PWD/UsernoticeMessage.cpp \
    $$PWD/ClearchatMessage.cpp

DEFINES += WEBSOCKET_LIBRARY

SRC_DIR     = $$PWD/src
HEADER_DIR  = $$PWD/include

INCLUDEPATH += $$SRC_DIR $$HEADER_DIR
DEPENDPATH += $$SRC_DIR $$HEADER_DIR

SOURCES += \
    $$SRC_DIR/WebSocket.cpp \
    $$SRC_DIR/IrcMessage.cpp

HEADERS += \
    $$HEADER_DIR/WebSocket_global.hpp \
    $$HEADER_DIR/WebSocket.hpp \
    $$HEADER_DIR/IrcMessage.hpp \
    $$HEADER_DIR/CommandHandler.hpp

SRC_DIR     = $$PWD/src
HEADER_DIR  = $$PWD/include

INCLUDEPATH += $$SRC_DIR $$HEADER_DIR
DEPENDPATH += $$SRC_DIR $$HEADER_DIR

SOURCES += \
    $$SRC_DIR/WebSocket.cpp \
    $$SRC_DIR/IrcMessage.cpp \
    $$SRC_DIR/PrivmsgMessage.cpp \
    $$SRC_DIR/UsernoticeMessage.cpp \
    $$SRC_DIR/ClearchatMessage.cpp

HEADERS += \
    $$HEADER_DIR/WebSocket_global.hpp \
    $$HEADER_DIR/WebSocket.hpp \
    $$HEADER_DIR/IrcMessage.hpp \
    $$HEADER_DIR/CommandHandler.hpp \
    $$HEADER_DIR/PrivmsgMessage.hpp \
    $$HEADER_DIR/UsernoticeMessage.hpp \
    $$HEADER_DIR/ClearchatMessage.hpp

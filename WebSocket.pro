QT -= gui
QT += core websockets

TEMPLATE = lib
DEFINES += WEBSOCKET_LIBRARY
DEFINES += WEBSOCKET_NAMESPACE EuleHaken::WebSocket # Default namespace, can be edited

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SRC_DIR     = $$PWD/src
HEADER_DIR  = $$PWD/include

INCLUDEPATH += $$SRC_DIR $$HEADER_DIR

SOURCES += \
    $$SRC_DIR/WebSocket.cpp \
    $$SRC_DIR/IrcMessage.cpp

HEADERS += \
    $$HEADER_DIR/WebSocket_global.hpp \
    $$HEADER_DIR/WebSocket.hpp \
    $$HEADER_DIR/IrcMessage.hpp \
    $$HEADER_DIR/CommandHandler.hpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

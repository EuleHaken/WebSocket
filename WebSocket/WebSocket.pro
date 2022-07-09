QT -= gui
QT += core websockets

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SRC_DIR     = $$PWD/src
HEADER_DIR  = $$PWD/include

INCLUDEPATH += $$SRC_DIR $$HEADER_DIR

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

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

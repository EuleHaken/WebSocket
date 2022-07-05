#pragma once

#include "WebSocket_global.hpp"
#include "IrcMessage.hpp"

#include <QWebSocket>

WEBSOCKET_BEGIN_NAMESPACE

class CommandHandler
{
public:
    virtual void handle(QWebSocket& socket, const IrcMessage& message) = 0;
};

WEBSOCKET_END_NAMESPACE

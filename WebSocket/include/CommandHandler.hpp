#pragma once

#include "WebSocket_global.hpp"
#include "IrcMessage.hpp"

WEBSOCKET_FORWARD_DECLARE_CLASS(WebSocket)

WEBSOCKET_BEGIN_NAMESPACE

class CommandHandler
{
public:
    virtual void handle(WebSocket& socket, IrcMessage& message) = 0;
};

WEBSOCKET_END_NAMESPACE

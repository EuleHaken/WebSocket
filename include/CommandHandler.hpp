#pragma once

#include "WebSocket_global.hpp"
#include "IrcMessage.hpp"

WEBSOCKET_FORWARD_DECLARE_CLASS(WebSocket)

WEBSOCKET_BEGIN_NAMESPACE

class WEBSOCKET_EXPORT CommandHandler
{
public:
    virtual void handle(WebSocket& socket, const IrcMessage& message) = 0;
};

WEBSOCKET_END_NAMESPACE

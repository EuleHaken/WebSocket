#pragma once

#include "IrcMessage.hpp"
#include "WebSocket_global.hpp"

WEBSOCKET_BEGIN_NAMESPACE

class WEBSOCKET_EXPORT ClearchatMessage final : public IrcMessage
{
public:
    ClearchatMessage(IrcMessage& parent);

private:
    /**
     * @brief The channel where the `CLEARCHAT` was raised
     */
    QString _channel;

    /**
     * @brief The user
     */
    QString _user;

};

WEBSOCKET_END_NAMESPACE

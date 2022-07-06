#pragma once

#include "IrcMessage.hpp"
#include "WebSocket_global.hpp"

WEBSOCKET_BEGIN_NAMESPACE

class UsernoticeMessage final : public IrcMessage
{
public:
    UsernoticeMessage(IrcMessage& parent);

public:
    const QString& getChannel() const;
    const QString& getMessage() const;
    const QString& getUser() const;
    const QString& getTarget() const;

private:
    /**
     * @brief The channel where the `USERNOTICE` was raised
     */
    QString _channel;

    /**
     * @brief The message, that was sent with the `USERNOTICE`
     * This could be a user subscribing to a channel and also sending a
     * message.
     */
    QString _message;

    /**
     * @brief The user that raised the `USERNOTICE`
     */
    QString _user;

    /**
     * @brief The target that the `USERNOTICE` goes to
     * This could be someone gifting another user a subscription
     */
    QString _target;
};

WEBSOCKET_END_NAMESPACE

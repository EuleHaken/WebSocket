#include "PrivmsgMessage.hpp"

WEBSOCKET_BEGIN_NAMESPACE

PrivmsgMessage::PrivmsgMessage(IrcMessage& parent)
    : IrcMessage(parent)
{
    assert(parent.getCommand() == "PRIVMSG");

    this->_username = parent.getPrefix().split('!').constFirst();
    this->_channel = parent.getParams().constLast();
    this->_message = parent.getParams().constLast();
}

const QString& PrivmsgMessage::getUsername() const
{
    return this->_username;
}

const QString& PrivmsgMessage::getChannel() const
{
    return this->_channel;
}

const QString& PrivmsgMessage::getMessage() const
{
    return this->_message;
}

WEBSOCKET_END_NAMESPACE

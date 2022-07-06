#include "UsernoticeMessage.hpp"

WEBSOCKET_BEGIN_NAMESPACE

UsernoticeMessage::UsernoticeMessage(IrcMessage& parent)
    : IrcMessage(parent)
{
    assert(parent.getCommand() == "USERNOTICE");

    this->_channel = parent.getParams().constFirst();
    this->_message = parent.getParams().constLast();
    this->_user = parent.getTags().key("display-name", "");
    this->_target =
        parent.getTags().key("msg-param-recipient-display-name", "");
}

const QString& UsernoticeMessage::getChannel() const
{
    return this->_channel;
}

const QString& UsernoticeMessage::getMessage() const
{
    return this->_message;
}

const QString& UsernoticeMessage::getUser() const
{
    return this->_user;
}

const QString& UsernoticeMessage::getTarget() const
{
    return this->_target;
}

WEBSOCKET_END_NAMESPACE

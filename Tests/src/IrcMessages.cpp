#include <gtest/gtest.h>

#include <QStringList>

#include <include/IrcMessage.hpp>
#include <include/WebSocket_global.hpp>

WEBSOCKET_USE_NAMESPACE

TEST(IrcMessages, IrcMessageParsingWorks)
{
    QStringList messages;
    messages
        << "@room-id=436590286;tmi-sent-ts=1657139595548 :tmi.twitch.tv "
           "CLEARCHAT #eulehaken"

        << "@ban-duration=5;room-id=436590286;target-user-id=100135110;tmi-"
           "sent-ts=1657139600173 :tmi.twitch.tv CLEARCHAT #eulehaken "
           ":eulehakenbot"

        << "PING :tmi.twitch.tv";

    foreach (const QString& message, messages)
    {
        IrcMessage msg = IrcMessage::parse(message);

        EXPECT_FALSE(msg.isEmpty());
    }
}

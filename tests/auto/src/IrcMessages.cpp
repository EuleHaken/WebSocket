#include <gtest/gtest.h>

#include <QStringList>

#include <ClearchatMessage.hpp>
#include <IrcMessage.hpp>
#include <PrivmsgMessage.hpp>
#include <UsernoticeMessage.hpp>
#include <WebSocket_global.hpp>

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

TEST(IrcMessages, ClearchatMessageConversion)
{
    // Example message from: https://dev.twitch.tv/docs/irc/tags#clearchat-tags
    IrcMessage message = IrcMessage::parse(
        "@room-id=12345678;target-user-id=87654321;tmi-sent-ts=1642715756806 "
        ":tmi.twitch.tv CLEARCHAT #dallas :ronni");

    EXPECT_NO_FATAL_FAILURE({ ClearchatMessage clearchat = message; });
}

TEST(IrcMessages, ClearchatMessageDeathTest)
{
    IrcMessage message = IrcMessage::parse("PING :tmi.twitch.tv");

    EXPECT_DEATH({ ClearchatMessage clearchat = message; }, "");
}

TEST(IrcMessages, PrivmsgMessageConversion)
{
    // Example message from: https://dev.twitch.tv/docs/irc/tags#privmsg-tags
    IrcMessage message = IrcMessage::parse(
        "@badge-info=;badges=turbo/"
        "1;color=#0D4200;display-name=ronni;emotes=25:0-4,12-16/"
        "1902:6-10;id=b34ccfc7-4977-403a-8a94-33c6bac34fb8;mod=0;room-id=1337;"
        "subscriber=0;tmi-sent-ts=1507246572675;turbo=1;user-id=1337;user-type="
        "global_mod :ronni!ronni@ronni.tmi.twitch.tv PRIVMSG #ronni :Kappa "
        "Keepo Kappa");

    EXPECT_NO_FATAL_FAILURE({ PrivmsgMessage privmsg = message; });
}

TEST(IrcMessages, PrivmsgMessageConversionDeathTest)
{
    IrcMessage message = IrcMessage::parse("PING :tmi.twitch.tv");

    EXPECT_DEATH({ PrivmsgMessage privmsg = message; }, "");
}

TEST(IrcMessages, UsernoticeMessageConversion)
{
    // Example message from: https://dev.twitch.tv/docs/irc/tags#usernotice-tags
    IrcMessage message = IrcMessage::parse(
        "@badge-info=;badges=staff/1,broadcaster/1,turbo/"
        "1;color=#008000;display-name=ronni;emotes=;id=db25007f-7a18-43eb-9379-"
        "80131e44d633;login=ronni;mod=0;msg-id=resub;msg-param-cumulative-"
        "months=6;msg-param-streak-months=2;msg-param-should-share-streak=1;"
        "msg-param-sub-plan=Prime;msg-param-sub-plan-name=Prime;room-id="
        "12345678;subscriber=1;system-msg="
        R"(ronni\shas\ssubscribed\sfor\s6\smonths!;tmi-sent-ts=1507246572675;)" // prepend with R to show that the "\s" should be spaces
        "turbo=1;user-id=87654321;user-type=staff :tmi.twitch.tv USERNOTICE "
        "#dallas :Great stream -- keep it up!");

    EXPECT_NO_FATAL_FAILURE({ UsernoticeMessage usernotice = message; });
}

TEST(IrcMessages, UsernoticeMessageConversionDeathTest)
{
    IrcMessage message = IrcMessage::parse("PING :tmi.twitch.tv");

    EXPECT_DEATH({ UsernoticeMessage usernotice = message; }, "");
}

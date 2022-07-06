#pragma once

#include "CommandHandler.hpp"
#include "IrcMessage.hpp"
#include "WebSocket_global.hpp"

#include <QHash>
#include <QObject>
#include <QStringList>
#include <QUrl>
#include <QWebSocket>

WEBSOCKET_BEGIN_NAMESPACE

class WEBSOCKET_EXPORT WebSocket : public QObject
{
    Q_OBJECT

public:
    explicit WebSocket(QObject* parent = nullptr);

signals:
    void incomingMessage(const IrcMessage& message);

public:
    /**
     * @brief Connects to the Web Socket
     */
    void connectToHost();

    /**
     * @brief Sets the nickname (NICK) for the client
     * @param nick nickname
     */
    WebSocket* setNick(const QString& nick);

    /**
     * @brief Sets the password (PASS) for the client
     * @param pass password
     */
    WebSocket* setPass(const QString& pass);

    /**
     * @brief Sets the url we should connect to
     * @param url Url
     */
    WebSocket* setUrl(const QString& url);

    /**
     * @brief Sends raw websocket/irc text/commands to the socket
     * @param text Text to send
     *
     * If we can't send messages to the socket yet - e.g. if its not connected yet -
     * we push the message into a queue. As soon as we are connected, all messages
     * in this queue get sent
     */
    void sendRaw(const QString& text);

    QWebSocket& getSocket();

    void setHandler(const QString& command, CommandHandler& handler);

private slots:
    void onConnected();
    void onIncomingMessage(const QString& message);
    // void onErrors();

private:
    void _write(const QString& text);

private:
    QWebSocket _socket;
    bool _isConnected;
    QStringList _messageQueue;

    QUrl _url;

    QString _nick;
    QString _pass;

    QHash<QString, QList<CommandHandler*>> _commandHandlers;
};

WEBSOCKET_END_NAMESPACE
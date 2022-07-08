#pragma once

#include "WebSocket_global.hpp"

#include <QDebug>
#include <QMap>
#include <QString>
#include <QStringList>

WEBSOCKET_BEGIN_NAMESPACE

class IrcMessage
{
public:
    const QString& getRawMessage() const;
    const QString& getPrefix() const;
    const QString& getCommand() const;

    const QStringList& getParams() const;

    const QMap<QString, QString>& getTags() const;

    bool isEmpty() const;

public:
    static const IrcMessage parse(const QString& text);

private:
    QString _rawMessage;
    QString _prefix;
    QString _command;

    QStringList _params;

    QMap<QString, QString> _tags;

protected:
    IrcMessage();
    IrcMessage(const QString& rawMsg, const QString& prefix,
               const QString& command, const QStringList& params,
               const QMap<QString, QString>& tags);
};

WEBSOCKET_END_NAMESPACE

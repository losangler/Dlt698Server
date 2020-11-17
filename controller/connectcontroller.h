#ifndef CONNECTCONTROLLER_H
#define CONNECTCONTROLLER_H

#include <QQmlEngine>
#include "service/serverservice.h"
#include "controller.h"

class ConnectController : public Controller
{
    Q_OBJECT

public:
    Q_INVOKABLE ServerModel *serverModel();

    Q_INVOKABLE void serverUpdate();

    Q_INVOKABLE void saveConfig();

    static QObject *singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    explicit ConnectController(QObject *parent = nullptr);

    ServerService *m_server;
};

#endif // CONNECTCONTROLLER_H

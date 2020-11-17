#include "connectcontroller.h"
#include "config/ConfigXml.h"

QObject *ConnectController::singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    ConnectController *example = new ConnectController();

    return example;
}

ConnectController::ConnectController(QObject *parent)
    : Controller(parent)
{
    this->m_server = new ServerService(this);
}

ServerModel *ConnectController::serverModel()
{
    return m_server->serverModel();
}

void ConnectController::serverUpdate()
{
    m_server->updateServer();
}

void ConnectController::saveConfig()
{
    ConfigXml::instance().Save();
}

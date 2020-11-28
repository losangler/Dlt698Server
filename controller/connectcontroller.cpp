#include "connectcontroller.h"
#include "config/ConfigXml.h"
#include <QDebug>

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
    this->m_tService = new TerminalService(this);
}

ServerModel *ConnectController::serverModel()
{
    return qobject_cast<ServerModel*>(m_server->model());
}

void ConnectController::serverUpdate()
{
    m_server->updateModel();
}

void ConnectController::saveConfig()
{
    ConfigXml::instance().Save();
}

void ConnectController::getAllTermianl()
{
    m_tService->test();
}


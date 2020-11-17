#include "serverservice.h"
#include "config/ConfigXml.h"

ServerService::ServerService(QObject *parent)
    : Service(parent)
{
    m_elem = ConfigXml::instance().getRoot().findChild(c_connection, c_server);
    this->m_serverModel = new ServerModel(
                m_elem.findChild(c_port).getText(),
                m_elem.findChild(c_timeout).getText(),
                m_elem.findChild(c_connectmax).getText(),
                m_elem.findChild(c_ip).getText(),
                this
                );
}

ServerModel *ServerService::serverModel() const
{
    return m_serverModel;
}

void ServerService::setServerModel(ServerModel *serverModel)
{
    m_serverModel = serverModel;
}

void ServerService::updateServer()
{
    m_elem.findChild(c_port).setText(m_serverModel->port());
    m_elem.findChild(c_timeout).setText(m_serverModel->timeOut());
    m_elem.findChild(c_connectmax).setText(m_serverModel->connectMax());
    m_elem.findChild(c_ip).setText(m_serverModel->ip());
}

#include "serverservice.h"
#include "config/ConfigXml.h"

#include <QMetaProperty>
#include <QDebug>

ServerService::ServerService(QObject *parent)
    : ConnectionService(parent)
{
    m_elem = ConfigXml::instance().getRoot().findChild(c_connection, c_server);
    m_model = new ServerModel(this);
    this->initModel();
}


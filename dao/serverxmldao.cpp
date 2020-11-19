#include "serverxmldao.h"
#include "config/ConfigXml.h"

ServerXmlDao::ServerXmlDao(QObject *parent)
    : XmlDao<ServerModel>::XmlDao(parent)
{
    this->m_elem = ConfigXml::instance().getRoot().findChild("connection", "server");
}


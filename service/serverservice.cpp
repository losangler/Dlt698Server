#include "serverservice.h"
#include "config/ConfigXml.h"

#include <QMetaProperty>
#include <QDebug>

ServerService::ServerService(QObject *parent)
    : ConnectionService(parent)
{
    m_model = m_dao.getModel();
}

Model *ServerService::model() const
{
    return m_model;
}

void ServerService::updateModel()
{
    m_dao.saveModel(*m_model);
}

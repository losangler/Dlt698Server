#include "connectionservice.h"
#include <QMetaProperty>

ConnectionService::ConnectionService(QObject *parent)
    : Service(parent)
{

}

Model *ConnectionService::model() const
{
    return m_model;
}

void ConnectionService::setModel(Model *model)
{
    m_model = model;
}

void ConnectionService::initModel()
{
    const QMetaObject* metaObj = m_model->metaObject();
    int propertyCnt = metaObj->propertyCount();
    for(int i = 0;i < propertyCnt; ++ i)
    {
        QMetaProperty oneProperty = metaObj->property(i);
        m_model->setProperty(oneProperty.name(), m_elem.findChild(oneProperty.name()).getText());
    }
}

void ConnectionService::updateModel()
{
    const QMetaObject* metaObj = m_model->metaObject();
    int propertyCnt = metaObj->propertyCount();
    for(int i = 0;i < propertyCnt; ++ i)
    {
        QMetaProperty oneProperty = metaObj->property(i);
        m_elem.findChild(oneProperty.name()).setText(m_model->property(oneProperty.name()).toString());
    }
}

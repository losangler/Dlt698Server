#include "model.h"
#include <QMetaProperty>

Model::Model(QObject *parent)
    : QObject(parent)
{

}

void Model::setNotNull(const QString &property)
{
    if(!m_property.contains(property))
    {
        m_property.insert(property);
    }
}

void Model::setNull(const QString &property)
{
    auto iter = m_property.find(property);
    if(iter != m_property.end())
    {
        m_property.erase(iter);
    }
}

bool Model::isNull(const QString &property)
{
    return !m_property.contains(property);
}


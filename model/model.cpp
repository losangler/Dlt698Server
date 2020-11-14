#include "model.h"

Model::Model(QObject *parent)
    : QObject(parent)
{

}

QString Model::userName()
{
    return this->m_userName;
}

void Model::setUserName(const QString &userName)
{
    if(userName == m_userName)
        return;

    this->m_userName = userName;
    emit userNameChanged();
}

#include "servermodel.h"
#include <QDebug>

ServerModel::ServerModel(QObject *parent) : Model(parent)
{

}

ServerModel::ServerModel(QString port, QString timeOut, QString connectMax, QString ip, QObject *parent)
    : Model(parent), m_port(port), m_timeOut(timeOut), m_connectMax(connectMax), m_ip(ip)
{

}

QString ServerModel::ip() const
{
    return m_ip;
}

void ServerModel::setIp(const QString &ip)
{
    if(m_ip == ip)
        return;
    m_ip = ip;
    emit ipChanged();
}

QString ServerModel::port() const
{
    return m_port;
}

void ServerModel::setPort(const QString &port)
{
    if(m_port == port)
        return;
    m_port = port;
    emit portChanged();
}

QString ServerModel::timeOut() const
{
    return m_timeOut;
}

void ServerModel::setTimeOut(const QString &timeOut)
{
    if(m_timeOut == timeOut)
        return;
    m_timeOut = timeOut;
    emit timeOutChanged();
}

QString ServerModel::connectMax() const
{
    return m_connectMax;
}

void ServerModel::setConnectMax(const QString &connectMax)
{
    if(m_connectMax == connectMax)
        return;
    m_connectMax = connectMax;
    emit connectMaxChanged();
}

#include "terminalmodel.h"
#include <QVariant>

TerminalModel::TerminalModel(QObject *parent)
    : Model(parent)
{

}

int TerminalModel::id() const
{
    return m_id;
}

void TerminalModel::setId(int id)
{
    this->setNotNull("id");

    if(m_id == id)
        return;
    m_id = id;
    emit idChanged();
}

QString TerminalModel::addr() const
{
    return m_addr;
}

void TerminalModel::setAddr(const QString &addr)
{
    this->setNotNull("addr");

    if(m_addr == addr)
        return;
    m_addr = addr;
    emit addrChanged();
}

int TerminalModel::status() const
{
    return m_status;
}

void TerminalModel::setStatus(int status)
{
    this->setNotNull("status");

    if(m_status == status)
        return;
    m_status = status;
    emit statusChanged();
}

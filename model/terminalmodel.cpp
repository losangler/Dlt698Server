#include "terminalmodel.h"

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
    if(m_status == status)
        return;
    m_status = status;
    emit statusChanged();
}

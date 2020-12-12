#include "terminalviewservice.h"
#include "util/dbmanager.h"

#include <QDebug>

TerminalViewService::TerminalViewService(QObject *parent)
    : Service(parent)
{

}

int TerminalViewService::getPages(int limit)
{
    if(limit <= 0)
       return 0;
    if(m_terminalView == nullptr)
        this->terminalView();

    DbManager manager;
    manager.query().prepare("select count(*) from v_terminal");
    manager.queryExec();
    if(manager.query().first())
    {
        return manager.query().value(0).toInt() / limit;
    }
    return 0;
}

QVariantMap TerminalViewService::getDateTimesAndCurrent()
{
    if(m_terminalView == nullptr)
        this->terminalView();

    QVariantMap res;
    int colTime = m_terminalView->record().indexOf("date_time");
    int colCurrent = m_terminalView->record().indexOf("current");
    for(int i = 0;i < m_terminalView->rowCount(); ++ i)
    {
        res.insert(m_terminalView->data(m_terminalView->index(i, colTime)).toString(),
                   m_terminalView->data(m_terminalView->index(i, colCurrent)));
    }
    return res;
}

QSqlQueryModel *TerminalViewService::terminalView(int offset, int limit)
{
    DbManager manager;
    manager.query().prepare("select * from v_terminal limit ? offset ?");
    manager.query().addBindValue(limit);
    manager.query().addBindValue(offset);
    manager.queryExec();
    if(m_terminalView == nullptr)
    m_terminalView = new QSqlQueryModel();
    m_terminalView->setQuery(manager.query());

    return m_terminalView;
}

void TerminalViewService::setTerminalView(QSqlQueryModel *terminalView)
{
    m_terminalView = terminalView;
}

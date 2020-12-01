#ifndef TERMINALSERVICE_H
#define TERMINALSERVICE_H

#include "service.h"
#include "dao/terminaldao.h"

class TerminalService : public Service
{
public:
    explicit TerminalService(QObject* parent = nullptr);

    void test();

    QSqlQueryModel* testSql();

private:
    TerminalDao m_dao;
};

#endif // TERMINALSERVICE_H

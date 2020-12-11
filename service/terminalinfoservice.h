#ifndef TERMINALINFOSERVICE_H
#define TERMINALINFOSERVICE_H

#include "service.h"
#include "dao/terminalinfodao.h"

class TerminalInfoService : public Service
{
public:
    explicit TerminalInfoService(QObject* parent = nullptr);

    void test();

private:
    TerminalInfoDao m_dao;
};

#endif // TERMINALINFOSERVICE_H

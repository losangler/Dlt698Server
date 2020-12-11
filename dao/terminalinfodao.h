#ifndef TERMINALINFODAO_H
#define TERMINALINFODAO_H

#include "databasedao.h"
#include "model/terminalinfomodel.h"

class TerminalInfoDao : public DataBaseDao<TerminalInfoModel>
{
public:
    explicit TerminalInfoDao(QObject* parent = nullptr);
};

#endif // TERMINALINFODAO_H

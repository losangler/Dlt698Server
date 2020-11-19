#ifndef TERMINALDAO_H
#define TERMINALDAO_H

#include "databasedao.h"
#include "model/terminalmodel.h"

class TerminalDao : public DataBaseDao<TerminalModel>
{
public:
    explicit TerminalDao(QObject* parent = nullptr);
};

#endif // TERMINALDAO_H

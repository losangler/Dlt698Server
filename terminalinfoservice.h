#ifndef TERMINALINFOSERVICE_H
#define TERMINALINFOSERVICE_H

#include "terminalinfoentity.h"
#include "databaseservice.h"

namespace Dlt698 {

class TerminalInfoService : public DataBaseService
{
public:
    TerminalInfoService();

    bool save(TerminalInfoEntity &entity);

    bool saveTest(TerminalInfoEntity &entity);
};

}

#endif // TERMINALINFOSERVICE_H

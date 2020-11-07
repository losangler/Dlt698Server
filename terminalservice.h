#ifndef TERMINALSERVICE_H
#define TERMINALSERVICE_H

#include "terminalentity.h"
#include "databaseservice.h"
#include <QSqlDatabase>
#include <list>

namespace Dlt698 {

class TerminalService : public DataBaseService
{
public:
    TerminalService();

    bool save(TerminalEntity &entity);

    TerminalEntity* getOne(int id);

    TerminalEntity* getOne(const std::string &addr);

    TerminalEntity* getOne(QSqlQuery &query);

    std::list<TerminalEntity*> getAll();
};

}

#endif // TERMINALSERVICE_H

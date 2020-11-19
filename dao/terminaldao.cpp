#include "terminaldao.h"

TerminalDao::TerminalDao(QObject *parent)
    : DataBaseDao<TerminalModel>::DataBaseDao("../Dlt698View/config/DBconfig.xml", "terminal", parent)
{

}

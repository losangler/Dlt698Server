#include "terminaldao.h"

TerminalDao::TerminalDao(QObject *parent)
    : DataBaseDao<TerminalModel>::DataBaseDao("terminal", parent)
{

}

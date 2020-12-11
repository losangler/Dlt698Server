#include "terminalinfodao.h"

TerminalInfoDao::TerminalInfoDao(QObject *parent)
    : DataBaseDao<TerminalInfoModel>::DataBaseDao("terminalInfo", parent)
{

}

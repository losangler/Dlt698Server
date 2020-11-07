#include "terminalentity.h"

using namespace Dlt698;

TerminalEntity::TerminalEntity()
    : id(0)
{

}

int TerminalEntity::getId() const
{
    return id;
}

void TerminalEntity::setId(int value)
{
    id = value;
}

std::string TerminalEntity::getAddr() const
{
    return addr;
}

void TerminalEntity::setAddr(const std::string &value)
{
    addr = value;
}

int TerminalEntity::getStatus() const
{
    return status;
}

void TerminalEntity::setStatus(int value)
{
    status = value;
}

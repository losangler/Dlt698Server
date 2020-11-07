#ifndef TERMINALENTITY_H
#define TERMINALENTITY_H

#include <string>

namespace Dlt698 {

class TerminalEntity
{
public:
    TerminalEntity();

    int getId() const;
    void setId(int value);

    std::string getAddr() const;
    void setAddr(const std::string &value);

    int getStatus() const;
    void setStatus(int value);

private:
    int id;
    std::string addr;
    int status;
};

}

#endif // TERMINALENTITY_H

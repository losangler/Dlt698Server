#ifndef TERMINALINFOENTITY_H
#define TERMINALINFOENTITY_H

#include <string>
#include "dlt698data.h"

namespace Dlt698 {

class TerminalInfoEntity
{
public:
    TerminalInfoEntity();

    int getId() const;
    void setId(int value);

    int getTerminalId() const;
    void setTerminalId(int value);

    int getCurrent() const;
    void setCurrent(int value);
    void setCurrent(shared_ptr<Dlt698Data> data);

    double getLongitude() const;
    void setLongitude(double value);
    void setLongitude(shared_ptr<Dlt698Data> data);

    double getLatitude() const;
    void setLatitude(double value);
    void setLatitude(shared_ptr<Dlt698Data> data);

    unsigned int getHeight() const;
    void setHeight(unsigned int value);

    std::string getDateTime() const;
    void setDateTime(const std::string &value);
    void setDateTime(shared_ptr<Dlt698Data> data);

private:
    int id;
    int terminalId;
    int current;
    double longitude;
    double latitude;
    unsigned int height;
    std::string dateTime;

private:
    double dataToCoord(shared_ptr<Dlt698Data> data);
};

}

#endif // TERMINALINFOENTITY_H

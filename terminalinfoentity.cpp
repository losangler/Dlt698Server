#include "terminalinfoentity.h"
#include "dlt698datetimes.h"

using namespace Dlt698;

TerminalInfoEntity::TerminalInfoEntity()
{

}

int TerminalInfoEntity::getId() const
{
    return id;
}

void TerminalInfoEntity::setId(int value)
{
    id = value;
}

int TerminalInfoEntity::getTerminalId() const
{
    return terminalId;
}

void TerminalInfoEntity::setTerminalId(int value)
{
    terminalId = value;
}

int TerminalInfoEntity::getCurrent() const
{
    return current;
}

void TerminalInfoEntity::setCurrent(int value)
{
    current = value;
}

void TerminalInfoEntity::setCurrent(shared_ptr<Dlt698Data> data)
{
    if(!data)
        return;

    shared_ptr<Dlt698Data> d = data;
    while(d->getETyp() != t_double_long && d->getChildsSize() > 0)
        d = d->getChild(0);

    if(d->getETyp() != t_double_long)
        return;

    size_t pos = 0;
    uint32_t c;
    Dlt698Proctol::baseDecode(d->getByDat(), pos, c);
    this->current = c;
}

double TerminalInfoEntity::getLongitude() const
{
    return longitude;
}

void TerminalInfoEntity::setLongitude(double value)
{
    longitude = value;
}

void TerminalInfoEntity::setLongitude(shared_ptr<Dlt698Data> data)
{
    this->longitude = this->dataToCoord(data);
}

double TerminalInfoEntity::getLatitude() const
{
    return latitude;
}

void TerminalInfoEntity::setLatitude(double value)
{
    latitude = value;
}

void TerminalInfoEntity::setLatitude(shared_ptr<Dlt698Data> data)
{
    this->latitude = this->dataToCoord(data);
}

unsigned int TerminalInfoEntity::getHeight() const
{
    return height;
}

void TerminalInfoEntity::setHeight(unsigned int value)
{
    height = value;
}

std::string TerminalInfoEntity::getDateTime() const
{
    return dateTime;
}

void TerminalInfoEntity::setDateTime(const std::string &value)
{
    dateTime = value;
}

void TerminalInfoEntity::setDateTime(shared_ptr<Dlt698Data> data)
{
    if(!data)
        return;

    Dlt698DateTimeS date;
    size_t pos = 0;
    date.decode(data->getByDat(), pos);
    this->dateTime = date.toString();
}

double TerminalInfoEntity::dataToCoord(shared_ptr<Dlt698Data> data)
{
    if(!data)
        return 0;

    shared_ptr<Dlt698Data> d = data;
    while(!(d->getETyp() == t_structure && d->getChildsSize() == 4) && d->getChildsSize() > 0)
        d = d->getChild(0);

    if(!(d->getETyp() == t_structure && d->getChildsSize() == 4))
        return 0;

    size_t pos;
    BYTE c;
    unsigned_c du,fen,miao;
    pos = 0;
    Dlt698Proctol::baseDecode(d->getChild(0)->getByDat(), pos, c);
    pos = 0;
    Dlt698Proctol::baseDecode(d->getChild(1)->getByDat(), pos, du);
    pos = 0;
    Dlt698Proctol::baseDecode(d->getChild(2)->getByDat(), pos, fen);
    pos = 0;
    Dlt698Proctol::baseDecode(d->getChild(3)->getByDat(), pos, miao);

    int fh = -1;
    if(c == 0)
        fh = 1;

    return fh * (du + (fen + (miao / 60.0)) / 60.0);
}

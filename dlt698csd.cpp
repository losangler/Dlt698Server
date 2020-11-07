#include "dlt698csd.h"

using namespace Csd;

Dlt698Csd::Dlt698Csd(eCSD csd) : eCsd(csd)
{
    switch(csd)
    {
    case _OAD:
        this->uscd = shared_ptr<Dlt698Oad>(new Dlt698Oad());
        break;
    case _ROAD:
        this->uscd = shared_ptr<Dlt698Road>(new Dlt698Road());
        break;
    default:
        break;
    }
}

Dlt698Csd::~Dlt698Csd()
{

}

void Dlt698Csd::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, (BYTE*)&this->eCsd, sizeof(BYTE));
    switch(this->eCsd)
    {
    case _OAD:
        this->uscd = shared_ptr<Dlt698Oad>(new Dlt698Oad());
        break;
    case _ROAD:
        this->uscd = shared_ptr<Dlt698Road>(new Dlt698Road());
        break;
    default:
        this->uscd = shared_ptr<Dlt698Proctol>(new Dlt698Proctol());
        break;
    }
    this->uscd->decode(res, pos);
}

void Dlt698Csd::encode(vector<BYTE> &res)
{
    this->baseEncode(res, (BYTE*)&this->eCsd, sizeof(BYTE));
    this->uscd->encode(res);
}

eCSD Dlt698Csd::getECsd() const
{
    return eCsd;
}

void Dlt698Csd::setECsd(const eCSD &value)
{
    eCsd = value;
}

shared_ptr<Dlt698Proctol> Dlt698Csd::getUscd() const
{
    return uscd;
}

void Dlt698Csd::setUscd(shared_ptr<Dlt698Proctol> value)
{
    uscd = value;
}

string Dlt698Csd::toString()
{
    DltStringBuffer buffer;
    buffer.append("eCSD", this->eCsd);
    buffer.append("UCSD", this->uscd->toString());
    return buffer.toString();
}

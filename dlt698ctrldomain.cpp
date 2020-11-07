#include "dlt698ctrldomain.h"

Dlt698CtrlDomain::Dlt698CtrlDomain()
{
    memset(&this->CtrlDomain, 0, sizeof(_tCONTROLDOMAIN));
}

void Dlt698CtrlDomain::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->CtrlDomain, sizeof(_tCONTROLDOMAIN));
}

void Dlt698CtrlDomain::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->CtrlDomain, sizeof(_tCONTROLDOMAIN));
}

string Dlt698CtrlDomain::toString()
{
    DltStringBuffer buffer;
    buffer.append("控制域", this->byteToString((BYTE*)&this->CtrlDomain, sizeof(_tCONTROLDOMAIN)));
    return buffer.toString();
}

BYTE Dlt698CtrlDomain::getFunc() const
{
    return this->CtrlDomain.func;
}

void Dlt698CtrlDomain::setFunc(const BYTE &value)
{
    this->CtrlDomain.func = value;
}

BYTE Dlt698CtrlDomain::getSc() const
{
    return this->CtrlDomain.sc;
}

void Dlt698CtrlDomain::setSc(const BYTE &value)
{
    this->CtrlDomain.sc = value;
}

BYTE Dlt698CtrlDomain::getRes() const
{
    return this->CtrlDomain.res;
}

void Dlt698CtrlDomain::setRes(const BYTE &value)
{
    this->CtrlDomain.res = value;
}

BYTE Dlt698CtrlDomain::getFrame() const
{
    return this->CtrlDomain.frame;
}

void Dlt698CtrlDomain::setFrame(const BYTE &value)
{
    this->CtrlDomain.frame = value;
}

BYTE Dlt698CtrlDomain::getPRM() const
{
    return this->CtrlDomain.PRM;
}

void Dlt698CtrlDomain::setPRM(const BYTE &value)
{
    this->CtrlDomain.PRM = value;
}

BYTE Dlt698CtrlDomain::getDIR() const
{
    return this->CtrlDomain.DIR;
}

void Dlt698CtrlDomain::setDIR(const BYTE &value)
{
    this->CtrlDomain.DIR = value;
}

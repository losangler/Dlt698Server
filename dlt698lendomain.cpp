#include "dlt698lendomain.h"
#include <QDebug>

Dlt698LenDomain::Dlt698LenDomain(WORD l, BYTE r)
{
    lenS.len = l;
    lenS.res = r;
}

void Dlt698LenDomain::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->lenS, sizeof(_LEN));
}

void Dlt698LenDomain::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->lenS, sizeof(_LEN));
}

string Dlt698LenDomain::toString()
{
    DltStringBuffer buffer;
    buffer.append("帧长度", this->byteToString((BYTE*)(&this->lenS), sizeof(WORD)));
    return buffer.toString();
}

WORD Dlt698LenDomain::getLen() const
{
    return lenS.len;
}

void Dlt698LenDomain::setLen(const WORD &value)
{
    lenS.len = value;
}

BYTE Dlt698LenDomain::getRes() const
{
    return lenS.res;
}

void Dlt698LenDomain::setRes(const BYTE &value)
{
    lenS.res = value;
}

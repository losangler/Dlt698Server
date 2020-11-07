#include "dlt698piid.h"

Dlt698Piid::Dlt698Piid()
{
    memset(&this->PIID, 0, sizeof(_tPIID));
}

string Dlt698Piid::toString()
{
    DltStringBuffer buffer;
    buffer.append("优先级", this->PIID.pri);
    buffer.append("请求状态", this->PIID.res);
    buffer.append("服务序号", this->PIID.idx);
    return buffer.toString();
}

void Dlt698Piid::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->PIID, sizeof(_tPIID));
}

void Dlt698Piid::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->PIID, sizeof(_tPIID));
}

unsigned_c Dlt698Piid::getIdx() const
{
    return this->PIID.idx;
}

void Dlt698Piid::setIdx(const unsigned_c &value)
{
    this->PIID.idx = value;
}

unsigned_c Dlt698Piid::getRes() const
{
    return this->PIID.res;
}

void Dlt698Piid::setRes(const unsigned_c &value)
{
    this->PIID.res = value;
}

unsigned_c Dlt698Piid::getPri() const
{
    return this->PIID.pri;
}

void Dlt698Piid::setPri(const unsigned_c &value)
{
    this->PIID.pri = value;
}

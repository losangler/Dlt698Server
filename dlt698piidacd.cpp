#include "dlt698piidacd.h"

Dlt698PiidAcd::Dlt698PiidAcd()
{
    memset(&this->PIID_ACD, 0, sizeof(_tPIID_ACD));
}

void Dlt698PiidAcd::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->PIID_ACD, sizeof(_tPIID_ACD));
}

void Dlt698PiidAcd::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->PIID_ACD, sizeof(_tPIID_ACD));
}

string Dlt698PiidAcd::toString()
{
    DltStringBuffer buffer;
    buffer.append("优先级", this->PIID_ACD.pri);
    buffer.append("请求状态", this->PIID_ACD.acd);
    buffer.append("服务序号", this->PIID_ACD.idx);
    return buffer.toString();
}

unsigned_c Dlt698PiidAcd::getPri() const
{
    return this->PIID_ACD.pri;
}

void Dlt698PiidAcd::setPri(const unsigned_c &value)
{
    this->PIID_ACD.pri = value;
}

unsigned_c Dlt698PiidAcd::getAcd() const
{
    return this->PIID_ACD.acd;
}

void Dlt698PiidAcd::setAcd(const unsigned_c &value)
{
    this->PIID_ACD.acd = value;
}

unsigned_c Dlt698PiidAcd::getIdx() const
{
    return this->PIID_ACD.idx;
}

void Dlt698PiidAcd::setIdx(const unsigned_c &value)
{
    this->PIID_ACD.idx = value;
}

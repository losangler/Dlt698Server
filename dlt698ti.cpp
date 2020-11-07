#include "dlt698ti.h"

using namespace _mTI;

Dlt698TI::Dlt698TI(eTi t, long_unsigned_c v)
    : unit(t), value(v)
{

}

void Dlt698TI::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->unit, sizeof(BYTE));
    this->baseDecode(res, pos, this->value);
}

void Dlt698TI::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->unit, sizeof(BYTE));
    this->baseEncode(res, this->value);
}

eTi Dlt698TI::getUnit() const
{
    return unit;
}

void Dlt698TI::setUnit(const eTi &value)
{
    unit = value;
}

long_unsigned_c Dlt698TI::getValue() const
{
    return value;
}

void Dlt698TI::setValue(const long_unsigned_c &value)
{
    this->value = value;
}

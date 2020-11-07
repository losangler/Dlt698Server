#include "dlt698timetag.h"

Dlt698TimeTag::Dlt698TimeTag()
{
    this->mark = shared_ptr<Dlt698DateTimeS>(new Dlt698DateTimeS());
    this->dalay = shared_ptr<Dlt698TI>(new Dlt698TI());
}

void Dlt698TimeTag::decode(const vector<BYTE> &res, size_t &pos)
{
    this->mark->decode(res, pos);
    this->dalay->decode(res, pos);
}

void Dlt698TimeTag::encode(vector<BYTE> &res)
{
    this->mark->encode(res);
    this->dalay->encode(res);
}

shared_ptr<Dlt698DateTimeS> Dlt698TimeTag::getMark() const
{
    return mark;
}

void Dlt698TimeTag::setMark(const shared_ptr<Dlt698DateTimeS> &value)
{
    mark = value;
}

shared_ptr<Dlt698TI> Dlt698TimeTag::getDalay() const
{
    return dalay;
}

void Dlt698TimeTag::setDalay(const shared_ptr<Dlt698TI> &value)
{
    dalay = value;
}

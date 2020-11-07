#include "dlt698getresponserecord.h"

Dlt698GetResponseRecord::Dlt698GetResponseRecord()
{
    this->piid = shared_ptr<Dlt698PiidAcd>(new Dlt698PiidAcd());
    this->record = shared_ptr<Dlt698ResultRecord>(new Dlt698ResultRecord());
}

void Dlt698GetResponseRecord::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->record->decode(res, pos);
}

void Dlt698GetResponseRecord::encode(vector<BYTE> &res)
{
    this->piid->encode(res);
    this->record->encode(res);
}

shared_ptr<Dlt698PiidAcd> Dlt698GetResponseRecord::getPiid() const
{
    return piid;
}

void Dlt698GetResponseRecord::setPiid(const shared_ptr<Dlt698PiidAcd> &value)
{
    piid = value;
}

shared_ptr<Dlt698ResultRecord> Dlt698GetResponseRecord::getRecord() const
{
    return record;
}

void Dlt698GetResponseRecord::setRecord(const shared_ptr<Dlt698ResultRecord> &value)
{
    record = value;
}

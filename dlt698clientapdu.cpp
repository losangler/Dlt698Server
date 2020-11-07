#include "dlt698clientapdu.h"

Dlt698ClientApdu::Dlt698ClientApdu(eClientAPDU type, bool_c tagExist)
    : sevType(type), timeTagExist(tagExist)
{
    this->timeTag = shared_ptr<Dlt698TimeTag>(new Dlt698TimeTag());
}

void Dlt698ClientApdu::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->sevType, sizeof(BYTE));
    this->baseEncode(this->body, &res[pos], res.size() - pos - 1);
    this->timeTagExist = false;
    pos = res.size();
}

void Dlt698ClientApdu::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->sevType, sizeof(BYTE));
    this->baseEncode(res, this->body.data(), this->body.size());
    this->baseEncode(res, &this->timeTagExist, sizeof(bool_c));
}

eClientAPDU Dlt698ClientApdu::getSevType() const
{
    return sevType;
}

void Dlt698ClientApdu::setSevType(const eClientAPDU &value)
{
    sevType = value;
}

vector<BYTE> Dlt698ClientApdu::getBody() const
{
    return body;
}

void Dlt698ClientApdu::setBody(const vector<BYTE> &value)
{
    body = value;
}

shared_ptr<Dlt698TimeTag> Dlt698ClientApdu::getTimeTag() const
{
    return timeTag;
}

void Dlt698ClientApdu::setTimeTag(const shared_ptr<Dlt698TimeTag> &value)
{
    timeTag = value;
}

bool_c Dlt698ClientApdu::getTimeTagExist() const
{
    return timeTagExist;
}

void Dlt698ClientApdu::setTimeTagExist(const bool_c &value)
{
    timeTagExist = value;
}

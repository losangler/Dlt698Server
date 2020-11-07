#include "dlt698serverapdu.h"

Dlt698ServerApdu::Dlt698ServerApdu(eServerAPDU type)
    : sevType(type), timeTagExist(false), followReportExist(false)
{
    this->timeTag = shared_ptr<Dlt698TimeTag>(new Dlt698TimeTag());
    this->followReport = shared_ptr<Dlt698FollowReport>(new Dlt698FollowReport());
}

void Dlt698ServerApdu::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->sevType, sizeof(BYTE));
    this->baseEncode(this->body, &res[pos], res.size() - pos - 2);
    this->timeTagExist = false;
    this->followReport = false;
    pos = res.size();
}

void Dlt698ServerApdu::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->sevType, sizeof(BYTE));
    this->baseEncode(res, this->body.data(), this->body.size());
    this->baseEncode(res, &this->timeTagExist, sizeof(bool_c));
    this->baseEncode(res, &this->followReportExist, sizeof(bool_c));
}

eServerAPDU Dlt698ServerApdu::getSevType() const
{
    return sevType;
}

void Dlt698ServerApdu::setSevType(const eServerAPDU &value)
{
    sevType = value;
}

vector<BYTE> Dlt698ServerApdu::getBody() const
{
    return body;
}

void Dlt698ServerApdu::setBody(const vector<BYTE> &value)
{
    body = value;
}

bool_c Dlt698ServerApdu::getFollowReportExist() const
{
    return followReportExist;
}

void Dlt698ServerApdu::setFollowReportExist(const bool_c &value)
{
    followReportExist = value;
}

shared_ptr<Dlt698FollowReport> Dlt698ServerApdu::getFollowReport() const
{
    return followReport;
}

void Dlt698ServerApdu::setFollowReport(const shared_ptr<Dlt698FollowReport> &value)
{
    followReport = value;
}

bool_c Dlt698ServerApdu::getTimeTagExist() const
{
    return timeTagExist;
}

void Dlt698ServerApdu::setTimeTagExist(const bool_c &value)
{
    timeTagExist = value;
}

shared_ptr<Dlt698TimeTag> Dlt698ServerApdu::getTimeTag() const
{
    return timeTag;
}

void Dlt698ServerApdu::setTimeTag(const shared_ptr<Dlt698TimeTag> &value)
{
    timeTag = value;
}

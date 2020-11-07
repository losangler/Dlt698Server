#include "dlt698reportnotification.h"

using namespace _mReportNotification;

Dlt698ReportNotification::Dlt698ReportNotification(eReportNotification type)
    : sevType(type)
{

}

void Dlt698ReportNotification::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->sevType, sizeof(BYTE));
    this->body.insert(this->body.end(), res.begin() + pos, res.end());
    pos = res.size();
}

void Dlt698ReportNotification::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->sevType, sizeof(BYTE));
    res.insert(res.end(), this->body.begin(), this->body.end());
}

eReportNotification Dlt698ReportNotification::getSevType() const
{
    return sevType;
}

void Dlt698ReportNotification::setSevType(const eReportNotification &value)
{
    sevType = value;
}

vector<BYTE> Dlt698ReportNotification::getBody() const
{
    return body;
}

void Dlt698ReportNotification::setBody(const vector<BYTE> &value)
{
    body = value;
}

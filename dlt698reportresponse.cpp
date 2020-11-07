#include "dlt698reportresponse.h"

using namespace _mReportResponse;

Dlt698ReportResponse::Dlt698ReportResponse()
{

}

void Dlt698ReportResponse::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->sevType, sizeof(BYTE));
    this->body.insert(this->body.end(), res.begin() + pos, res.end());
    pos = res.size();
}

void Dlt698ReportResponse::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->sevType, sizeof(BYTE));
    res.insert(res.end(), this->body.begin(), this->body.end());
}

eReportResponse Dlt698ReportResponse::getSevType() const
{
    return sevType;
}

void Dlt698ReportResponse::setSevType(const eReportResponse &value)
{
    sevType = value;
}

vector<BYTE> Dlt698ReportResponse::getBody() const
{
    return body;
}

void Dlt698ReportResponse::setBody(const vector<BYTE> &value)
{
    body = value;
}

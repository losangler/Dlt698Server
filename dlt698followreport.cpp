#include "dlt698followreport.h"

Dlt698FollowReport::Dlt698FollowReport(reportType t)
    : type(t)
{

}

void Dlt698FollowReport::decode(const vector<BYTE> &res, size_t &pos)
{

}

void Dlt698FollowReport::encode(vector<BYTE> &res)
{

}

Dlt698FollowReport::reportType Dlt698FollowReport::getType() const
{
    return type;
}

void Dlt698FollowReport::setType(const reportType &value)
{
    type = value;
}

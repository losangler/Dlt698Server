#include "dlt698linkrequest.h"

using namespace _mLinkRequest;

Dlt698LinkRequest::Dlt698LinkRequest()
{
    this->piid = shared_ptr<Dlt698PiidAcd>(new Dlt698PiidAcd());
    this->reqtime = shared_ptr<Dlt698DateTime>(new Dlt698DateTime());
}

string Dlt698LinkRequest::toString()
{

}

void Dlt698LinkRequest::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->baseDecode(res, pos, &this->sevType, sizeof(BYTE));
    this->baseDecode(res, pos, this->heartcycle);
    this->reqtime->decode(res, pos);
}

void Dlt698LinkRequest::encode(vector<BYTE> &res)
{
    this->piid->encode(res);
    this->baseEncode(res, &this->sevType, sizeof(BYTE));
    this->baseEncode(res, this->heartcycle);
    this->reqtime->encode(res);
}

shared_ptr<Dlt698PiidAcd> Dlt698LinkRequest::getPiid() const
{
    return piid;
}

void Dlt698LinkRequest::setPiid(const shared_ptr<Dlt698PiidAcd> &value)
{
    piid = value;
}

eReqTyp Dlt698LinkRequest::getSevType() const
{
    return sevType;
}

void Dlt698LinkRequest::setSevType(const eReqTyp &value)
{
    sevType = value;
}

long_unsigned_c Dlt698LinkRequest::getHeartcycle() const
{
    return heartcycle;
}

void Dlt698LinkRequest::setHeartcycle(const long_unsigned_c &value)
{
    heartcycle = value;
}

shared_ptr<Dlt698DateTime> Dlt698LinkRequest::getReqtime() const
{
    return reqtime;
}

void Dlt698LinkRequest::setReqtime(const shared_ptr<Dlt698DateTime> &value)
{
    reqtime = value;
}

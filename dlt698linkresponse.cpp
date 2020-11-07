#include "dlt698linkresponse.h"

Dlt698LinkResponse::Dlt698LinkResponse()
{
    this->piid = shared_ptr<Dlt698Piid>(new Dlt698Piid());

    BYTE buff = 0;
    this->result = *(_Result*)&buff;
    this->requestTime = shared_ptr<Dlt698DateTime>(new Dlt698DateTime());
    this->receiveTime = shared_ptr<Dlt698DateTime>(new Dlt698DateTime());
    this->responseTime = shared_ptr<Dlt698DateTime>(new Dlt698DateTime());
}

void Dlt698LinkResponse::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->baseDecode(res, pos, &this->result, sizeof(_Result));
    this->receiveTime->decode(res, pos);
    this->receiveTime->decode(res, pos);
    this->responseTime->decode(res, pos);
}

void Dlt698LinkResponse::encode(vector<BYTE> &res)
{
    this->piid->encode(res);
    this->baseEncode(res, &this->result, sizeof(_Result));
    this->requestTime->encode(res);
    this->receiveTime->encode(res);
    this->responseTime->encode(res);
}

shared_ptr<Dlt698Piid> Dlt698LinkResponse::getPiid() const
{
    return piid;
}

void Dlt698LinkResponse::setPiid(const shared_ptr<Dlt698Piid> &value)
{
    piid = value;
}

shared_ptr<Dlt698DateTime> Dlt698LinkResponse::getRequestTime() const
{
    return requestTime;
}

void Dlt698LinkResponse::setRequestTime(const shared_ptr<Dlt698DateTime> &value)
{
    requestTime = value;
}

shared_ptr<Dlt698DateTime> Dlt698LinkResponse::getReceiveTime() const
{
    return receiveTime;
}

void Dlt698LinkResponse::setReceiveTime(const shared_ptr<Dlt698DateTime> &value)
{
    receiveTime = value;
}

shared_ptr<Dlt698DateTime> Dlt698LinkResponse::getResponseTime() const
{
    return responseTime;
}

void Dlt698LinkResponse::setResponseTime(const shared_ptr<Dlt698DateTime> &value)
{
    responseTime = value;
}

BYTE Dlt698LinkResponse::getClock() const
{
    return this->result.clock;
}

void Dlt698LinkResponse::setClock(const BYTE clock)
{
    this->result.clock = clock;
}

BYTE Dlt698LinkResponse::getRslt() const
{
    return this->result.rslt;
}

void Dlt698LinkResponse::setRslt(const BYTE rslt)
{
    this->result.rslt = rslt;
}

BYTE Dlt698LinkResponse::getRes() const
{
    return this->result.res;
}

void Dlt698LinkResponse::setRes(const BYTE res)
{
    this->result.res = res;
}


#include "dlt698connectrequest.h"

Dlt698ConnectRequest::Dlt698ConnectRequest()
{
    this->piid = shared_ptr<Dlt698Piid>(new Dlt698Piid());
    this->protconf = shared_ptr<Dlt698ProtocolConformance>(new Dlt698ProtocolConformance());
    this->funconf = shared_ptr<Dlt698FunctionConformance>(new Dlt698FunctionConformance());
    this->mechanisminfo = shared_ptr<Dlt698ConnectMechanismInfo>(new Dlt698ConnectMechanismInfo());
}

void Dlt698ConnectRequest::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->baseDecode(res, pos, this->protver);
    this->protconf->decode(res, pos);
    this->funconf->decode(res, pos);
    this->baseDecode(res, pos, this->clisndframemaxsize);
    this->baseDecode(res, pos, this->clircvframemaxsize);
    this->baseDecode(res, pos, this->clircvframemaxwindow);
    this->baseDecode(res, pos, this->cliapdumaxsize);
    this->baseDecode(res, pos, this->connecttimeout);
    this->mechanisminfo->decode(res, pos);
}

void Dlt698ConnectRequest::encode(vector<BYTE> &res)
{
    this->piid->encode(res);
    this->baseEncode(res, this->protver);
    this->protconf->encode(res);
    this->funconf->encode(res);
    this->baseEncode(res, this->clisndframemaxsize);
    this->baseEncode(res, this->clircvframemaxsize);
    this->baseEncode(res, this->clircvframemaxwindow);
    this->baseEncode(res, this->cliapdumaxsize);
    this->baseEncode(res, this->connecttimeout);
    this->mechanisminfo->encode(res);
}

shared_ptr<Dlt698Piid> Dlt698ConnectRequest::getPiid() const
{
    return piid;
}

void Dlt698ConnectRequest::setPiid(const shared_ptr<Dlt698Piid> &value)
{
    piid = value;
}

long_unsigned_c Dlt698ConnectRequest::getProtver() const
{
    return protver;
}

void Dlt698ConnectRequest::setProtver(const long_unsigned_c &value)
{
    protver = value;
}

shared_ptr<Dlt698ProtocolConformance> Dlt698ConnectRequest::getProtconf() const
{
    return protconf;
}

void Dlt698ConnectRequest::setProtconf(const shared_ptr<Dlt698ProtocolConformance> &value)
{
    protconf = value;
}

shared_ptr<Dlt698FunctionConformance> Dlt698ConnectRequest::getFunconf() const
{
    return funconf;
}

void Dlt698ConnectRequest::setFunconf(const shared_ptr<Dlt698FunctionConformance> &value)
{
    funconf = value;
}

long_unsigned_c Dlt698ConnectRequest::getClisndframemaxsize() const
{
    return clisndframemaxsize;
}

void Dlt698ConnectRequest::setClisndframemaxsize(const long_unsigned_c &value)
{
    clisndframemaxsize = value;
}

long_unsigned_c Dlt698ConnectRequest::getClircvframemaxsize() const
{
    return clircvframemaxsize;
}

void Dlt698ConnectRequest::setClircvframemaxsize(const long_unsigned_c &value)
{
    clircvframemaxsize = value;
}

unsigned_c Dlt698ConnectRequest::getClircvframemaxwindow() const
{
    return clircvframemaxwindow;
}

void Dlt698ConnectRequest::setClircvframemaxwindow(const unsigned_c &value)
{
    clircvframemaxwindow = value;
}

long_unsigned_c Dlt698ConnectRequest::getCliapdumaxsize() const
{
    return cliapdumaxsize;
}

void Dlt698ConnectRequest::setCliapdumaxsize(const long_unsigned_c &value)
{
    cliapdumaxsize = value;
}

double_long_unsigned_c Dlt698ConnectRequest::getConnecttimeout() const
{
    return connecttimeout;
}

void Dlt698ConnectRequest::setConnecttimeout(const double_long_unsigned_c &value)
{
    connecttimeout = value;
}

shared_ptr<Dlt698ConnectMechanismInfo> Dlt698ConnectRequest::getMechanisminfo() const
{
    return mechanisminfo;
}

void Dlt698ConnectRequest::setMechanisminfo(const shared_ptr<Dlt698ConnectMechanismInfo> &value)
{
    mechanisminfo = value;
}

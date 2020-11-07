#include "dlt698connectresponse.h"

using namespace _ConnectResponse;

Dlt698ConnectResponse::Dlt698ConnectResponse()
{
    this->piid = shared_ptr<Dlt698Piid>(new Dlt698Piid());
    this->factoryver = shared_ptr<FactoryVersion>(new FactoryVersion());
    this->protconf = shared_ptr<Dlt698ProtocolConformance>(new Dlt698ProtocolConformance());
    this->funconf = shared_ptr<Dlt698FunctionConformance>(new Dlt698FunctionConformance());
    this->responseInfo = shared_ptr<Dlt698ConnectResponseInfo>(new Dlt698ConnectResponseInfo());
}

void Dlt698ConnectResponse::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->factoryver->decode(res, pos);
    this->baseDecode(res, pos, this->protver);
    this->protconf->decode(res, pos);
    this->funconf->decode(res, pos);
    this->baseDecode(res, pos, this->clisndframemaxsize);
    this->baseDecode(res, pos, this->clircvframemaxsize);
    this->baseDecode(res, pos, this->clircvframemaxwindow);
    this->baseDecode(res, pos, this->cliapdumaxsize);
    this->baseDecode(res, pos, this->connecttimeout);
    this->responseInfo->decode(res, pos);
}

void Dlt698ConnectResponse::encode(vector<BYTE> &res)
{
    this->piid->encode(res);
    this->factoryver->encode(res);
    this->baseEncode(res, this->protver);
    this->protconf->encode(res);
    this->funconf->encode(res);
    this->baseEncode(res, this->clisndframemaxsize);
    this->baseEncode(res, this->clircvframemaxsize);
    this->baseEncode(res, this->clircvframemaxwindow);
    this->baseEncode(res, this->cliapdumaxsize);
    this->baseEncode(res, this->connecttimeout);
    this->responseInfo->encode(res);
}

shared_ptr<Dlt698Piid> Dlt698ConnectResponse::getPiid() const
{
    return piid;
}

void Dlt698ConnectResponse::setPiid(const shared_ptr<Dlt698Piid> &value)
{
    piid = value;
}

long_unsigned_c Dlt698ConnectResponse::getProtver() const
{
    return protver;
}

void Dlt698ConnectResponse::setProtver(const long_unsigned_c &value)
{
    protver = value;
}

shared_ptr<Dlt698ProtocolConformance> Dlt698ConnectResponse::getProtconf() const
{
    return protconf;
}

void Dlt698ConnectResponse::setProtconf(const shared_ptr<Dlt698ProtocolConformance> &value)
{
    protconf = value;
}

shared_ptr<Dlt698FunctionConformance> Dlt698ConnectResponse::getFunconf() const
{
    return funconf;
}

void Dlt698ConnectResponse::setFunconf(const shared_ptr<Dlt698FunctionConformance> &value)
{
    funconf = value;
}

long_unsigned_c Dlt698ConnectResponse::getClisndframemaxsize() const
{
    return clisndframemaxsize;
}

void Dlt698ConnectResponse::setClisndframemaxsize(const long_unsigned_c &value)
{
    clisndframemaxsize = value;
}

long_unsigned_c Dlt698ConnectResponse::getClircvframemaxsize() const
{
    return clircvframemaxsize;
}

void Dlt698ConnectResponse::setClircvframemaxsize(const long_unsigned_c &value)
{
    clircvframemaxsize = value;
}

unsigned_c Dlt698ConnectResponse::getClircvframemaxwindow() const
{
    return clircvframemaxwindow;
}

void Dlt698ConnectResponse::setClircvframemaxwindow(const unsigned_c &value)
{
    clircvframemaxwindow = value;
}

long_unsigned_c Dlt698ConnectResponse::getCliapdumaxsize() const
{
    return cliapdumaxsize;
}

void Dlt698ConnectResponse::setCliapdumaxsize(const long_unsigned_c &value)
{
    cliapdumaxsize = value;
}

double_long_unsigned_c Dlt698ConnectResponse::getConnecttimeout() const
{
    return connecttimeout;
}

void Dlt698ConnectResponse::setConnecttimeout(const double_long_unsigned_c &value)
{
    connecttimeout = value;
}

shared_ptr<_ConnectResponse::FactoryVersion> Dlt698ConnectResponse::getFactoryver() const
{
    return factoryver;
}

void Dlt698ConnectResponse::setFactoryver(const shared_ptr<_ConnectResponse::FactoryVersion> &value)
{
    factoryver = value;
}

shared_ptr<Dlt698ConnectResponseInfo> Dlt698ConnectResponse::getResponseInfo() const
{
    return responseInfo;
}

void Dlt698ConnectResponse::setResponseInfo(const shared_ptr<Dlt698ConnectResponseInfo> &value)
{
    responseInfo = value;
}

/***************************************************************/



void FactoryVersion::setFactoryCodeById(const size_t &id, const visible_string_c &value)
{
    this->factorycode.at(id);
    this->factorycode[id] = value;
}

visible_string_c FactoryVersion::getFactoryCodeById(size_t &id) const
{
    return this->factorycode.at(id);
}

void FactoryVersion::setSoftWareverById(const size_t &id, const visible_string_c &value)
{
    this->softwarever.at(id);
    this->softwarever[id] = value;
}

visible_string_c FactoryVersion::getSoftWareverById(const size_t &id) const
{
    return this->softwarever.at(id);
}

void FactoryVersion::setSoftWareDateById(const size_t &id, const visible_string_c &value)
{
    this->softwaredate.at(id);
    this->softwaredate[id] = value;
}

visible_string_c FactoryVersion::getSoftWareDateById(const size_t &id) const
{
    return this->softwaredate.at(id);
}

void FactoryVersion::setHardWareverById(const size_t &id, const visible_string_c &value)
{
    this->hardwarever.at(id);
    this->hardwarever[id] = value;
}

visible_string_c FactoryVersion::getHardWareverById(const size_t &id) const
{
    return this->hardwarever.at(id);
}

void FactoryVersion::setHardWareDateById(const size_t &id, const visible_string_c &value)
{
    this->hardwaredate.at(id);
    this->hardwaredate[id] = value;
}

visible_string_c FactoryVersion::getHardWareDateById(const size_t &id) const
{
    return this->hardwaredate.at(id);
}

void FactoryVersion::setFactoryExtentById(const size_t &id, const visible_string_c &value)
{
    this->factoryextent.at(id);
    this->factoryextent[id] = value;
}

visible_string_c FactoryVersion::getFactoryExtentById(const size_t &id) const
{
    return this->factoryextent.at(id);
}

void FactoryVersion::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->factorycode.data(), this->factorycode.size() * sizeof(visible_string_c));
    this->baseDecode(res, pos, this->softwarever.data(), this->softwarever.size() * sizeof(visible_string_c));
    this->baseDecode(res, pos, this->softwaredate.data(), this->softwaredate.size() * sizeof(visible_string_c));
    this->baseDecode(res, pos, this->hardwarever.data(), this->hardwarever.size() * sizeof(visible_string_c));
    this->baseDecode(res, pos, this->hardwaredate.data(), this->hardwaredate.size() * sizeof(visible_string_c));
    this->baseDecode(res, pos, this->factoryextent.data(), this->factoryextent.size() * sizeof(visible_string_c));
}

void FactoryVersion::encode(vector<BYTE> &res)
{
    this->baseEncode(res, this->factorycode.data(), this->factorycode.size() * sizeof(visible_string_c));
    this->baseEncode(res, this->softwarever.data(), this->softwarever.size() * sizeof(visible_string_c));
    this->baseEncode(res, this->softwaredate.data(), this->softwaredate.size() * sizeof(visible_string_c));
    this->baseEncode(res, this->hardwarever.data(), this->hardwarever.size() * sizeof(visible_string_c));
    this->baseEncode(res, this->hardwaredate.data(), this->hardwaredate.size() * sizeof(visible_string_c));
    this->baseEncode(res, this->factoryextent.data(), this->factoryextent.size() * sizeof(visible_string_c));
}

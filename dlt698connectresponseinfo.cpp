#include "dlt698connectresponseinfo.h"

using namespace ConnectResponseInfo;

Dlt698ConnectResponseInfo::Dlt698ConnectResponseInfo(eConnectResult r)
    : result(r)
{

}

void Dlt698ConnectResponseInfo::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->result, sizeof(BYTE));
    this->baseDecode(res, pos, this->num);
    for(auto &k : this->securData)
    {
        k->decode(res, pos);
    }
}

void Dlt698ConnectResponseInfo::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->result, sizeof(BYTE));
    this->num = this->securData.size();
    this->baseEncode(res, this->num);
    for(auto &k : this->securData)
    {
        k->encode(res);
    }
}

eConnectResult Dlt698ConnectResponseInfo::getResult() const
{
    return result;
}

void Dlt698ConnectResponseInfo::setResult(const eConnectResult &value)
{
    result = value;
}

vector<shared_ptr<SecurityData> > Dlt698ConnectResponseInfo::getSecurData() const
{
    return securData;
}

void Dlt698ConnectResponseInfo::setSecurData(const vector<shared_ptr<SecurityData> > &value)
{
    securData = value;
}

/**************************************************************/

shared_ptr<Dlt698RandNum> SecurityData::getRn() const
{
    return rn;
}

void SecurityData::setRn(const shared_ptr<Dlt698RandNum> &value)
{
    rn = value;
}

SecurityData::SecurityData()
{
    this->rn = shared_ptr<Dlt698RandNum>(new Dlt698RandNum());
}

vector<Octet_string_c> SecurityData::getSignate() const
{
    return signate;
}

void SecurityData::setSignate(const vector<Octet_string_c> &value)
{
    signate = value;
}

void SecurityData::decode(const vector<BYTE> &res, size_t &pos)
{
    this->rn->decode(res, pos);
    this->baseDecode(res, pos, this->num);
    this->signate.resize(this->num, 0);
    for(auto &k : this->signate)
    {
        this->baseDecode(res, pos, k);
    }
}

void SecurityData::encode(vector<BYTE> &res)
{
    this->rn->encode(res);
    this->num = this->signate.size();
    this->baseEncode(res, this->num);
    for(auto &k : this->signate)
    {
        this->baseEncode(res, k);
    }
}

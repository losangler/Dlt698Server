#include "dlt698getresponsenormal.h"

using namespace Dlt698;

Dlt698GetResponseNormal::Dlt698GetResponseNormal()
{
    this->piid = shared_ptr<Dlt698PiidAcd>(new Dlt698PiidAcd());
    this->result = shared_ptr<ResultNormal>(new ResultNormal());
}

shared_ptr<Dlt698::ResultNormal> Dlt698GetResponseNormal::getResult() const
{
    return result;
}

void Dlt698GetResponseNormal::setResult(const shared_ptr<Dlt698::ResultNormal> &value)
{
    result = value;
}

shared_ptr<Dlt698PiidAcd> Dlt698GetResponseNormal::getPiid() const
{
    return piid;
}

void Dlt698GetResponseNormal::setPiid(const shared_ptr<Dlt698PiidAcd> &value)
{
    piid = value;
}

void Dlt698GetResponseNormal::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->result->decode(res, pos);
}

void Dlt698GetResponseNormal::encode(vector<BYTE> &res)
{
    this->piid->encode(res);
    this->result->encode(res);
}

ResultNormal::ResultNormal()
 : resultType(_Data)
{
    this->oad = shared_ptr<Dlt698Oad>(new Dlt698Oad());
    this->result = shared_ptr<Get_Result>(new Get_Result());
}

shared_ptr<Dlt698Oad> ResultNormal::getOad() const
{
    return oad;
}

void ResultNormal::setOad(const shared_ptr<Dlt698Oad> &value)
{
    oad = value;
}

shared_ptr<Get_Result> ResultNormal::getResult() const
{
    return result;
}

void ResultNormal::setResult(const shared_ptr<Get_Result> &value)
{
    result = value;
}

eGetResult ResultNormal::getResultType() const
{
    return resultType;
}

void ResultNormal::setResultType(const eGetResult &value)
{
    resultType = value;
}

void ResultNormal::decode(const vector<BYTE> &res, size_t &pos)
{
    this->oad->decode(res, pos);
    this->baseDecode(res, pos, &this->resultType, sizeof(BYTE));
    if(this->resultType == _DAR)
    {
        this->baseDecode(res, pos, &this->result->dar, sizeof(BYTE));
    }
    else if(this->resultType == _Data)
    {
        this->result->data->decode(res, pos);
    }
}

void ResultNormal::encode(vector<BYTE> &res)
{
    this->oad->encode(res);
    this->baseEncode(res, (BYTE)this->resultType);
    if(this->resultType == _DAR)
    {
        this->baseEncode(res, (BYTE)this->result->dar);
    }
    else if(this->resultType == _Data)
    {
        this->result->data->encode(res);
    }
}

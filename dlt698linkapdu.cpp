#include "dlt698linkapdu.h"

Dlt698LinkApdu::Dlt698LinkApdu()
{

}

string Dlt698LinkApdu::toString()
{

}

void Dlt698LinkApdu::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->sevType, sizeof(BYTE));
    this->body.insert(this->body.end(), res.begin() + pos, res.end());
    pos = res.size();
}

void Dlt698LinkApdu::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->sevType, sizeof(BYTE));
    res.insert(res.end(), this->body.begin(), this->body.end());
}

eLinkAPDU Dlt698LinkApdu::getSevType() const
{
    return sevType;
}

void Dlt698LinkApdu::setSevType(const eLinkAPDU &value)
{
    sevType = value;
}

vector<BYTE> Dlt698LinkApdu::getBody() const
{
    return body;
}

void Dlt698LinkApdu::setBody(const vector<BYTE> &value)
{
    body = value;
}

#include "dlt698randnum.h"

Dlt698RandNum::Dlt698RandNum()
{

}

void Dlt698RandNum::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->num);
    this->dat.resize(this->num, 0);
    for(auto &k : this->dat)
    {
        this->baseDecode(res, pos, k);
    }
}

void Dlt698RandNum::encode(vector<BYTE> &res)
{
    this->num = this->dat.size();
    this->baseEncode(res, this->num);
    for(auto &k : this->dat)
    {
        this->baseEncode(res, k);
    }
}

BYTE Dlt698RandNum::getNum() const
{
    return this->dat.size();
}

void Dlt698RandNum::setNum(const BYTE &value)
{
    num = value;
}

vector<Octet_string_c> Dlt698RandNum::getDat() const
{
    return dat;
}

void Dlt698RandNum::setDat(const vector<Octet_string_c> &value)
{
    dat = value;
}

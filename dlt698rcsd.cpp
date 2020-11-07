#include "dlt698rcsd.h"

Dlt698Rcsd::Dlt698Rcsd(BYTE n) : num(n)
{
    this->pCsd = vector<shared_ptr<Dlt698Csd> >(n);
}

void Dlt698Rcsd::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->num);
    for(BYTE i = 0;i < this->num; i ++)
    {
        this->pCsd.push_back(shared_ptr<Dlt698Csd>(new Dlt698Csd()));
        this->pCsd[i]->decode(res, pos);
    }
}

void Dlt698Rcsd::encode(vector<BYTE> &res)
{
    this->num = this->pCsd.size();
    this->baseEncode(res, this->num);
    for(auto &k : this->pCsd)
    {
        k->encode(res);
    }
}

string Dlt698Rcsd::toString()
{
    DltStringBuffer buffer;
    buffer.append("长度", this->pCsd.size());

    vector<shared_ptr<DltObject> > objects(this->pCsd.begin(), this->pCsd.end());
    buffer.append("CSDS", objects);
    return buffer.toString();
}

BYTE Dlt698Rcsd::getNum() const
{
    return this->pCsd.size();
}

void Dlt698Rcsd::setNum(const BYTE &value)
{
    num = value;
}

vector<shared_ptr<Dlt698Csd> > Dlt698Rcsd::getPCsd() const
{
    return pCsd;
}

void Dlt698Rcsd::setPCsd(const vector<shared_ptr<Dlt698Csd> > &value)
{
    pCsd = value;
}

void Dlt698Rcsd::addCsd(shared_ptr<Dlt698Csd> csd)
{
    this->pCsd.push_back(csd);
    this->num = this->pCsd.size();
}

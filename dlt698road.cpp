#include "dlt698road.h"

Dlt698Road::Dlt698Road(BYTE n) : num(n)
{
    this->oad = shared_ptr<Dlt698Oad>(new Dlt698Oad());
    this->pOAD = vector<shared_ptr<Dlt698Oad> >(n);
}

Dlt698Road::~Dlt698Road()
{

}

void Dlt698Road::decode(const vector<BYTE> &res, size_t &pos)
{
    this->oad->decode(res, pos);
    this->baseDecode(res, pos, this->num);
    for(auto &k : this->pOAD)
    {
        k->decode(res, pos);
    }
}

void Dlt698Road::encode(vector<BYTE> &res)
{
    this->oad->encode(res);
    this->num = this->pOAD.size();
    this->baseEncode(res, this->num);
    for(auto &k : this->pOAD)
    {
        k->encode(res);
    }
}

shared_ptr<Dlt698Oad> Dlt698Road::getOad() const
{
    return oad;
}

void Dlt698Road::setOad(shared_ptr<Dlt698Oad> value)
{
    oad = value;
}

BYTE Dlt698Road::getNum() const
{
    return this->pOAD.size();
}

void Dlt698Road::setNum(const BYTE &value)
{
    num = value;
}

vector<shared_ptr<Dlt698Oad> > Dlt698Road::getPOAD() const
{
    return pOAD;
}

void Dlt698Road::setPOAD(const vector<shared_ptr<Dlt698Oad> > &value)
{
    pOAD = value;
}

void Dlt698Road::addOAD(shared_ptr<Dlt698Oad> value)
{
    this->pOAD.push_back(value);
    this->num = this->pOAD.size();
}

#include "dlt698getresponsenormallist.h"

Dlt698GetResponseNormalList::Dlt698GetResponseNormalList()
{
    this->piid = shared_ptr<Dlt698PiidAcd>(new Dlt698PiidAcd());
    this->num = 0;
}

void Dlt698GetResponseNormalList::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->baseDecode(res, pos, &num, sizeof(BYTE));
    for(int i = 0;i < num;i ++)
    {
        shared_ptr<Dlt698::ResultNormal> result(new Dlt698::ResultNormal());
        result->decode(res, pos);
        this->results.push_back(result);
    }
}

void Dlt698GetResponseNormalList::encode(vector<BYTE> &res)
{
    this->piid->encode(res);

    num = this->results.size();
    this->baseEncode(res, num);
    for(auto &k : this->results)
    {
        k->encode(res);
    }
}

shared_ptr<Dlt698PiidAcd> Dlt698GetResponseNormalList::getPiid() const
{
    return piid;
}

void Dlt698GetResponseNormalList::setPiid(const shared_ptr<Dlt698PiidAcd> &value)
{
    piid = value;
}

vector<shared_ptr<Dlt698::ResultNormal> > Dlt698GetResponseNormalList::getResults() const
{
    return results;
}

void Dlt698GetResponseNormalList::setResults(const vector<shared_ptr<Dlt698::ResultNormal> > &value)
{
    results = value;
}

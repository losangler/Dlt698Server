#include "dlt698reportresponserecordlist.h"

Dlt698ReportResponseRecordList::Dlt698ReportResponseRecordList()
{
    this->piid = shared_ptr<Dlt698Piid>(new Dlt698Piid());
    this->num = 0;
}

void Dlt698ReportResponseRecordList::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->baseDecode(res, pos, this->num);
    for(int i = 0;i < this->num;i ++)
    {
        shared_ptr<Dlt698Oad> oad(new Dlt698Oad());
        oad->decode(res, pos);
        this->oads.push_back(oad);
    }
}

void Dlt698ReportResponseRecordList::encode(vector<BYTE> &res)
{
    this->piid->encode(res);
    this->num = this->oads.size();
    this->baseEncode(res, this->num);
    for(auto &k : this->oads)
    {
        k->encode(res);
    }
}

shared_ptr<Dlt698Piid> Dlt698ReportResponseRecordList::getPiid() const
{
    return piid;
}

void Dlt698ReportResponseRecordList::setPiid(const shared_ptr<Dlt698Piid> &value)
{
    piid = value;
}

BYTE Dlt698ReportResponseRecordList::getNum() const
{
    return this->oads.size();
}

void Dlt698ReportResponseRecordList::setNum(const BYTE &value)
{
    num = value;
}

vector<shared_ptr<Dlt698Oad> > Dlt698ReportResponseRecordList::getOads() const
{
    return oads;
}

void Dlt698ReportResponseRecordList::setOads(const vector<shared_ptr<Dlt698Oad> > &value)
{
    oads = value;
}

void Dlt698ReportResponseRecordList::addOad(const shared_ptr<Dlt698Oad> &oad)
{
    this->oads.push_back(oad);
}

shared_ptr<Dlt698Oad> Dlt698ReportResponseRecordList::getOad(BYTE id) const
{
    return this->oads.at(id);
}

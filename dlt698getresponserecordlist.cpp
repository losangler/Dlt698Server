#include "dlt698getresponserecordlist.h"

Dlt698GetResponseRecordList::Dlt698GetResponseRecordList()
{
    this->piid = shared_ptr<Dlt698PiidAcd>(new Dlt698PiidAcd());
    this->paRsltrec = vector<shared_ptr<Dlt698ResultRecord> >();
}

void Dlt698GetResponseRecordList::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->baseDecode(res, pos, &num, sizeof(BYTE));
    for(int i = 0;i < num;i ++)
    {
        shared_ptr<Dlt698ResultRecord> record(new Dlt698ResultRecord());
        record->decode(res, pos);
        this->paRsltrec.push_back(record);
    }
}

void Dlt698GetResponseRecordList::encode(vector<BYTE> &res)
{
    this->piid->encode(res);

    num = this->paRsltrec.size();
    this->baseEncode(res, &num, sizeof(BYTE));
    for(auto &k : this->paRsltrec)
    {
        k->encode(res);
    }
}

string Dlt698GetResponseRecordList::toString()
{
    DltStringBuffer buffer;
    buffer.append("PIIDACD", this->piid->toString());

    string str = "[";
    for(size_t i = 0; i < this->paRsltrec.size();i ++)
    {
        str.append(this->paRsltrec[i]->toString());
        if(i != this->paRsltrec.size() - 1)
            str.append(", ");
    }
    str.append("]");
    buffer.append("RECORDS", str);
    return buffer.toString();
}

shared_ptr<Dlt698PiidAcd> Dlt698GetResponseRecordList::getPiid() const
{
    return piid;
}

void Dlt698GetResponseRecordList::setPiid(const shared_ptr<Dlt698PiidAcd> &value)
{
    piid = value;
}

vector<shared_ptr<Dlt698ResultRecord> > Dlt698GetResponseRecordList::getPaRsltrec() const
{
    return paRsltrec;
}

void Dlt698GetResponseRecordList::setPaRsltrec(const vector<shared_ptr<Dlt698ResultRecord> > &value)
{
    paRsltrec = value;
}

void Dlt698GetResponseRecordList::addRecord(shared_ptr<Dlt698ResultRecord> record)
{
    this->paRsltrec.push_back(record);
}

shared_ptr<Dlt698ResultRecord> Dlt698GetResponseRecordList::getRecordById(size_t id)
{
    if(id >= this->paRsltrec.size())
        return nullptr;
    return this->paRsltrec[id];
}


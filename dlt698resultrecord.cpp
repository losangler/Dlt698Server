#include "dlt698resultrecord.h"

using namespace _mResultRecod;

Dlt698ResultRecord::Dlt698ResultRecord(eResponseData data, eDAR d)
    : choiceRespDat(data), dar(d)
{
    this->oad = shared_ptr<Dlt698Oad>(new Dlt698Oad());
    this->rcsd = shared_ptr<Dlt698Rcsd>(new Dlt698Rcsd());
    this->pDat = vector<shared_ptr<Dlt698Data> >();
}

void Dlt698ResultRecord::decode(const vector<BYTE> &res, size_t &pos)
{
    this->oad->decode(res, pos);
    this->rcsd->decode(res, pos);
    this->baseDecode(res, pos, &this->choiceRespDat, sizeof(BYTE));
    switch(this->choiceRespDat)
    {
    case _DAR:
        this->baseDecode(res, pos, &this->dar, sizeof(BYTE));
        break;
    case _RecordRow:
    {
        BYTE num;
        this->baseDecode(res, pos, num);
        for(int i = 0;i < num * 2;i ++)
        {
            shared_ptr<Dlt698Data> data(new Dlt698Data());
            data->decode(res, pos);
            this->pDat.push_back(data);
        }
    }
        break;
    default:
        break;
    }
}

void Dlt698ResultRecord::encode(vector<BYTE> &res)
{
    this->oad->encode(res);
    this->rcsd->encode(res);
    this->baseEncode(res, &this->choiceRespDat, sizeof(BYTE));
    switch(this->choiceRespDat)
    {
    case _DAR:
        this->baseEncode(res, &this->dar, sizeof(BYTE));
        break;
    case _RecordRow:
    {
        BYTE num = this->pDat.size() / 2;
        this->baseEncode(res, num);
        for(auto &k : this->pDat)
        {
            k->encode(res);
        }
    }
        break;
    default:
        break;
    }
}

shared_ptr<Dlt698Oad> Dlt698ResultRecord::getOad() const
{
    return oad;
}

void Dlt698ResultRecord::setOad(const shared_ptr<Dlt698Oad> &value)
{
    oad = value;
}

shared_ptr<Dlt698Rcsd> Dlt698ResultRecord::getRcsd() const
{
    return rcsd;
}

void Dlt698ResultRecord::setRcsd(const shared_ptr<Dlt698Rcsd> &value)
{
    rcsd = value;
}

eResponseData Dlt698ResultRecord::getChoiceRespDat() const
{
    return choiceRespDat;
}

void Dlt698ResultRecord::setChoiceRespDat(const eResponseData &value)
{
    choiceRespDat = value;
}

eDAR Dlt698ResultRecord::getDar() const
{
    return dar;
}

void Dlt698ResultRecord::setDar(const eDAR &value)
{
    dar = value;
}

vector<shared_ptr<Dlt698Data> > Dlt698ResultRecord::getPDat() const
{
    return pDat;
}

void Dlt698ResultRecord::setPDat(const vector<shared_ptr<Dlt698Data> > &value)
{
    pDat = value;
}

void Dlt698ResultRecord::addData(shared_ptr<Dlt698Data> dat)
{
    this->pDat.push_back(dat);
}

string Dlt698ResultRecord::toString()
{
    DltStringBuffer buffer;
    buffer.append("OAD", this->oad->toString());
    buffer.append("RCSD", this->rcsd->toString());
    buffer.append("数据类型", this->choiceRespDat);
    buffer.append("DAR", this->dar);

    vector<shared_ptr<DltObject> > objects(this->pDat.begin(), this->pDat.end());
    buffer.append("DATAS", objects);
    return buffer.toString();
}

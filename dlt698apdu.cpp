#include "dlt698apdu.h"
#include "QDebug"

Dlt698Apdu::Dlt698Apdu()
    : byStart(0x68), byEnd(0x16)
{
    this->len = shared_ptr<Dlt698LenDomain>(new Dlt698LenDomain());
    this->ctrl = shared_ptr<Dlt698CtrlDomain>(new Dlt698CtrlDomain());
    this->SA = shared_ptr<Dlt698SrvAddr>(new Dlt698SrvAddr());
}

void Dlt698Apdu::decode(const vector<BYTE> &res, size_t &pos)
{
    BYTE cp[res.size()];
    memcpy(&cp, &res[0], res.size());

    while (pos < res.size() && res[pos] != this->byStart) {
        pos ++;
    }
    pos ++;

    int start = pos;
    this->len->decode(res, pos);
    if(this->len->getLen() <= this->baseLen)
    {
        qDebug() << "帧长度过短" << this->len->getLen();
        pos = 0;
        return;
    }
    else if(this->len->getLen() > res.size() - start - 1)
    {
        qDebug() << "帧长度过长" << this->len->getLen();
        pos = 0;
        return;
    }

    this->ctrl->decode(res, pos);
    this->SA->decode(res, pos);
    this->baseDecode(res, pos, &this->byCA, sizeof(BYTE));
    this->baseDecode(res, pos, &this->wHCS, sizeof(WORD));
    if(this->judgeFcs16(&cp[start], pos - start - sizeof(WORD), this->wHCS) == false)
    {
        qDebug() << "帧头校验错误" << hex << this->wHCS;
        pos = 0;
        return;
    }
    this->headLen = this->SA->getSize() + this->baseLen;
    this->bodyLen = this->len->getLen() - this->headLen;
    this->baseEncode(this->byASDU, &res[pos], this->bodyLen);
    pos += this->bodyLen;
    this->baseDecode(res, pos, &this->wFCS, sizeof(WORD));
    if(this->judgeFcs16(&cp[start], pos - start - sizeof(WORD), this->wFCS) == false)
    {
        qDebug() << "全帧校验错误" << hex << this->wFCS;
        pos = 0;
        return;
    }
    if(res[pos] != this->byEnd)
    {
        qDebug() << "帧尾不存在";
        pos = 0;
        return;
    }
    if(this->len->getLen() != pos - start)
    {
        qDebug() << "帧长度错误";
        pos = 0;
    }
}

void Dlt698Apdu::encode(vector<BYTE> &res)
{
    this->bodyLen = this->byASDU.size();
    this->headLen = this->SA->getSize() + this->baseLen;

    this->len->setLen(this->bodyLen + this->headLen);

    this->baseEncode(res, &this->byStart, sizeof(BYTE));

    BYTE start = res.size();
    this->len->encode(res);
    this->ctrl->encode(res);
    this->SA->encode(res);
    this->baseEncode(res, &this->byCA, sizeof(BYTE));

    this->wHCS = this->checkfcs16(&res[start], res.size() - start);

    this->baseEncode(res, &this->wHCS, sizeof(WORD));

    this->baseEncode(res, &this->byASDU[0], this->bodyLen);

    this->wFCS = this->checkfcs16(&res[start], res.size() - start);
    this->baseEncode(res, &this->wFCS, sizeof(WORD));

    this->baseEncode(res, &this->byEnd, sizeof(BYTE));
}

string Dlt698Apdu::toString()
{
    DltStringBuffer buffer;
    buffer.append("帧起始", this->byteToString(&this->byStart, sizeof(BYTE)));
    buffer.append("LEN", this->getLen()->toString());
    buffer.append("CTRL", this->ctrl->toString());
    buffer.append("SRVADDR", this->SA->toString());
    buffer.append("客户机地址:", this->byteToString(&this->byCA, sizeof(BYTE)));
    buffer.append("帧头校验", this->byteToString((BYTE*)&this->wHCS, sizeof(WORD)));
    if(this->byASDU.size() <= 0)
        buffer.append("ASDU", "");
    else buffer.append("ASDU", this->byteToString(&this->byASDU[0], this->byASDU.size()));
    buffer.append("帧校验", this->byteToString((BYTE*)&this->wFCS, sizeof(WORD)));
    buffer.append("帧结尾", this->byteToString(&this->byEnd, sizeof(BYTE)));
    return buffer.toString();
}

BYTE Dlt698Apdu::getByStart() const
{
    return byStart;
}

shared_ptr<Dlt698LenDomain> Dlt698Apdu::getLen() const
{
    return len;
}

void Dlt698Apdu::setLen(const shared_ptr<Dlt698LenDomain> &value)
{
    len = value;
}

shared_ptr<Dlt698CtrlDomain> Dlt698Apdu::getCtrl() const
{
    return ctrl;
}

void Dlt698Apdu::setCtrl(const shared_ptr<Dlt698CtrlDomain> &value)
{
    ctrl = value;
}

shared_ptr<Dlt698SrvAddr> Dlt698Apdu::getSA() const
{
    return SA;
}

void Dlt698Apdu::setSA(const shared_ptr<Dlt698SrvAddr> &value)
{
    SA = value;
}

BYTE Dlt698Apdu::getByCA() const
{
    return byCA;
}

void Dlt698Apdu::setByCA(const BYTE &value)
{
    byCA = value;
}

WORD Dlt698Apdu::getWHCS() const
{
    return wHCS;
}

void Dlt698Apdu::setWHCS(const WORD &value)
{
    wHCS = value;
}

vector<BYTE> Dlt698Apdu::getByASDU() const
{
    return byASDU;
}

void Dlt698Apdu::setByASDU(const vector<BYTE> &value)
{
    byASDU = value;
}

WORD Dlt698Apdu::getWFCS() const
{
    return wFCS;
}

void Dlt698Apdu::setWFCS(const WORD &value)
{
    wFCS = value;
}

BYTE Dlt698Apdu::getByEnd() const
{
    return byEnd;
}

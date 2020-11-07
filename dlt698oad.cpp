#include "dlt698oad.h"
#include <arpa/inet.h>

Dlt698Oad::Dlt698Oad()
{
    memset(&this->OAD, 0, sizeof(_tOAD));
}

void Dlt698Oad::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->oi);
    this->baseDecode(res, pos, &this->OAD, sizeof(_tOAD));
}

void Dlt698Oad::encode(vector<BYTE> &res)
{
    this->baseEncode(res, this->oi);
    this->baseEncode(res, &this->OAD, sizeof(_tOAD));
}

string Dlt698Oad::toString()
{
    DltStringBuffer buffer;
    buffer.append("对象标识", this->byteToString((BYTE*)&this->oi, sizeof(WORD)));
    buffer.append("属性标识", this->OAD.attrId);
    buffer.append("属性特征", this->OAD.attrFea);
    buffer.append("属性内元素索引", this->OAD.elemIdx);
    return buffer.toString();
}

OI_c Dlt698Oad::getOi() const
{
    return oi;
}

void Dlt698Oad::setOi(const OI_c &value)
{
    oi = value;
}

unsigned_c Dlt698Oad::getAttrId() const
{
    return this->OAD.attrId;
}

void Dlt698Oad::setAttrId(const unsigned_c &value)
{
    this->OAD.attrId = value;
}

unsigned_c Dlt698Oad::getAttrFea() const
{
    return this->OAD.attrFea;
}

void Dlt698Oad::setAttrFea(const unsigned_c &value)
{
    this->OAD.attrFea = value;
}

unsigned_c Dlt698Oad::getElemIdx() const
{
    return this->OAD.elemIdx;
}

void Dlt698Oad::setElemIdx(const unsigned_c &value)
{
    this->OAD.elemIdx = value;
}

#include "dlt698srvaddr.h"

Dlt698SrvAddr::Dlt698SrvAddr()
{
    memset(&this->SrvAddr, 0, sizeof(_tSrvAddr));
}

void Dlt698SrvAddr::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->SrvAddr, sizeof(_tSrvAddr));
    this->baseEncode(this->AddrDat, &res[pos], this->SrvAddr.addrLen + 1);
    pos += this->AddrDat.size();
}

void Dlt698SrvAddr::encode(vector<BYTE> &res)
{
    this->SrvAddr.addrLen = this->AddrDat.size() - 1;
    this->baseEncode(res, &this->SrvAddr, sizeof(_tSrvAddr));
    res.insert(res.end(), this->AddrDat.begin(), this->AddrDat.end());
}

string Dlt698SrvAddr::toString()
{
    DltStringBuffer buffer;
    buffer.append("帧长度", this->SrvAddr.addrLen);
    buffer.append("逻辑地址", this->SrvAddr.logicAddr);
    buffer.append("地址类型：", this->SrvAddr.addrType);
    if(this->AddrDat.size() <= 0)
        buffer.append("服务器地址", "");
    else buffer.append("服务器地址", this->byteToString(&this->AddrDat[0], this->AddrDat.size()));
    return buffer.toString();
}

BYTE Dlt698SrvAddr::getAddrLen() const
{
    return this->SrvAddr.addrLen;
}

void Dlt698SrvAddr::setAddrLen(const BYTE &value)
{
    this->SrvAddr.addrLen = value;
}

BYTE Dlt698SrvAddr::getLogicAddr() const
{
    return this->SrvAddr.logicAddr;
}

void Dlt698SrvAddr::setLogicAddr(const BYTE &value)
{
    this->SrvAddr.logicAddr = value;
}

BYTE Dlt698SrvAddr::getAddrType() const
{
    return this->SrvAddr.addrType;
}

void Dlt698SrvAddr::setAddrType(const BYTE &value)
{
    this->SrvAddr.addrType = value;
}

vector<BYTE> Dlt698SrvAddr::getAddrDat() const
{
    return AddrDat;
}

void Dlt698SrvAddr::setAddrDat(const vector<BYTE> &value)
{
    AddrDat = value;
}

BYTE Dlt698SrvAddr::getSize() const
{
    return sizeof(_tSrvAddr) + this->AddrDat.size();
}

void Dlt698SrvAddr::addAddrDat(const BYTE &addr)
{
    this->AddrDat.push_back(addr);
}

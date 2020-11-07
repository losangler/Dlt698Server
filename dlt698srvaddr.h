#ifndef DLT698SRVADDR_H
#define DLT698SRVADDR_H

#include "dlt698proctol.h"

class Dlt698SrvAddr : public Dlt698Proctol
{
public:
    Dlt698SrvAddr();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;
    string toString() override;

    BYTE getAddrLen() const;
    void setAddrLen(const BYTE &value);

    BYTE getLogicAddr() const;
    void setLogicAddr(const BYTE &value);

    BYTE getAddrType() const;
    void setAddrType(const BYTE &value);

    vector<BYTE> getAddrDat() const;
    void setAddrDat(const vector<BYTE> &value);

    BYTE getSize() const;
    void addAddrDat(const BYTE &addr);
private:
    struct _tSrvAddr
    {
        BYTE addrLen:4;
        BYTE logicAddr:2;
        BYTE addrType:2;
        /*
        SingleAddr=0,//单地址
        GeneralAddr,//通配地址
        GroupAddr,//组地址
        BroadcastAddr//广播地址
        */

    }SrvAddr;

    vector<BYTE> AddrDat;
};

#endif // DLT698SRVADDR_H

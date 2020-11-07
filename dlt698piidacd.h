#ifndef DLT698PIIDACD_H
#define DLT698PIIDACD_H

#include "dlt698proctol.h"

class Dlt698PiidAcd : public Dlt698Proctol
{
public:
    Dlt698PiidAcd();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;
    string toString() override;

    unsigned_c getPri() const;
    void setPri(const unsigned_c &value);

    unsigned_c getAcd() const;
    void setAcd(const unsigned_c &value);

    unsigned_c getIdx() const;
    void setIdx(const unsigned_c &value);

private:

    struct _tPIID_ACD
    {
        unsigned_c pri:1;//优先级
        unsigned_c acd:1;//0:不请求 1：请求
        unsigned_c idx:6;//服务序号

    }PIID_ACD;
};

#endif // DLT698PIIDACD_H

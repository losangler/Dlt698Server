#ifndef DLT698PIID_H
#define DLT698PIID_H

#include "dlt698proctol.h"

class Dlt698Piid : public Dlt698Proctol
{
public:
    Dlt698Piid();

private:
    struct _tPIID
    {
        unsigned_c pri:1;//优先级
        unsigned_c res:1;//
        unsigned_c idx:6;//服务序号
    }PIID;

    // DltObject interface
public:
    string toString();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    unsigned_c getPri() const;
    void setPri(const unsigned_c &value);
    unsigned_c getRes() const;
    void setRes(const unsigned_c &value);
    unsigned_c getIdx() const;
    void setIdx(const unsigned_c &value);
};

#endif // DLT698PIID_H

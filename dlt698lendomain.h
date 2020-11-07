#ifndef DLT698LENDOMAIN_H
#define DLT698LENDOMAIN_H

#include "dlt698proctol.h"

class Dlt698LenDomain : public Dlt698Proctol
{
public:
    Dlt698LenDomain(WORD l = 0, BYTE r = 0);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;
    string toString() override;

    WORD getLen() const;
    void setLen(const WORD &value);

    BYTE getRes() const;
    void setRes(const BYTE &value);

private:
    struct _LEN{
        WORD len:14 ;
        BYTE res:2 ;
    }lenS;
};

#endif // DLT698LENDOMAIN_H

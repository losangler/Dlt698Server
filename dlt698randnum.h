#ifndef DLT698RANDNUM_H
#define DLT698RANDNUM_H

#include "dlt698proctol.h"

class Dlt698RandNum : public Dlt698Proctol
{
public:
    Dlt698RandNum();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    BYTE getNum() const;
    void setNum(const BYTE &value);

    vector<Octet_string_c> getDat() const;
    void setDat(const vector<Octet_string_c> &value);

private:
    BYTE num;
    vector<Octet_string_c> dat;

};

#endif // DLT698RANDNUM_H

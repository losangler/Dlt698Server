#ifndef DLT698LINKAPDU_H
#define DLT698LINKAPDU_H

#include "dlt698proctol.h"

class Dlt698LinkApdu : public Dlt698Proctol
{
public:
    Dlt698LinkApdu();

    // DltObject interface
public:
    string toString();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    eLinkAPDU getSevType() const;
    void setSevType(const eLinkAPDU &value);

    vector<BYTE> getBody() const;
    void setBody(const vector<BYTE> &value);

private:
    eLinkAPDU sevType;

    vector<BYTE> body;
};

#endif // DLT698LINKAPDU_H

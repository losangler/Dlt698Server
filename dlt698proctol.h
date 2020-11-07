#ifndef DLT698PROCTOL_H
#define DLT698PROCTOL_H

#include "dlt698proctol_global.h"
#include "dlt698datatypes.h"
#include "dltstringbuffer.h"
#include "dltobject.h"
#include <vector>
#include <string.h>
#include <arpa/inet.h>

using namespace std;

class DLT698PROCTOLSHARED_EXPORT Dlt698Proctol : public DltObject
{

public:
    virtual void decode(const vector<BYTE> &res, size_t &pos);

    virtual void encode(vector<BYTE> &res);

    virtual string toString();

    virtual ~Dlt698Proctol(){}

    string toHexString();

    vector<BYTE> toBytes();
public:
    static string byteToString(const BYTE convert_data[], int convert_len);

    static void baseEncode(vector<BYTE> &res, const void *data, size_t size);

    static void baseDecode(const vector<BYTE> &res, size_t &pos, void *data, size_t size);

    static void baseEncode(vector<BYTE> &res, uint16_t netshort);

    static void baseEncode(vector<BYTE> &res, uint32_t netlong);

    static void baseDecode(const vector<BYTE> &res, size_t &pos, uint16_t &netshort);

    static void baseDecode(const vector<BYTE> &res, size_t &pos, uint32_t &netlong);

    static void baseEncode(vector<BYTE> &res, uint8_t netbyte);

    static void baseDecode(const vector<BYTE> &res, size_t &pos, uint8_t &netbyte);

};

#endif // DLT698PROCTOL_H

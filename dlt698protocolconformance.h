#ifndef DLT698PROTOCOLCONFORMANCE_H
#define DLT698PROTOCOLCONFORMANCE_H

#include <array>
#include "dlt698proctol.h"

class Dlt698ProtocolConformance : public Dlt698Proctol
{
public:
    Dlt698ProtocolConformance();

    // DltObject interface
public:
    string toString();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    void setConfoById(const size_t &id, const bit_string_c &value);
    bit_string_c getConfoById(const size_t &id) const;
private:
    array<bit_string_c, 8> confo;
};

#endif // DLT698PROTOCOLCONFORMANCE_H

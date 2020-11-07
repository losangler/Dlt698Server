#include "dlt698protocolconformance.h"

Dlt698ProtocolConformance::Dlt698ProtocolConformance()
{
    this->confo.fill(0xFF);
}

string Dlt698ProtocolConformance::toString()
{

}

void Dlt698ProtocolConformance::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->confo.data(), this->confo.size() * sizeof(bit_string_c));
}

void Dlt698ProtocolConformance::encode(vector<BYTE> &res)
{
    this->baseEncode(res, this->confo.data(), this->confo.size() * sizeof(bit_string_c));
}

void Dlt698ProtocolConformance::setConfoById(const size_t &id, const bit_string_c &value)
{
    this->confo.at(id);
    this->confo[id] = value;
}

bit_string_c Dlt698ProtocolConformance::getConfoById(const size_t &id) const
{
    return this->confo.at(id);
}

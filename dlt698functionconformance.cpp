#include "dlt698functionconformance.h"

Dlt698FunctionConformance::Dlt698FunctionConformance()
{
    this->confo.fill(0xFF);
}

string Dlt698FunctionConformance::toString()
{

}

void Dlt698FunctionConformance::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->confo.data(), this->confo.size() * sizeof(bit_string_c));
}

void Dlt698FunctionConformance::encode(vector<BYTE> &res)
{
    this->baseEncode(res, this->confo.data(), this->confo.size() * sizeof(bit_string_c));
}

void Dlt698FunctionConformance::setConfoById(const size_t &id, const bit_string_c &value)
{
    this->confo.at(id);
    this->confo[id] = value;
}

bit_string_c Dlt698FunctionConformance::getConfoById(const size_t &id) const
{
    return this->confo.at(id);
}

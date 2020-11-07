#ifndef DLT698TI_H
#define DLT698TI_H

#include "dlt698proctol.h"

namespace _mTI {

typedef enum _eTi{
    second,
    minute,
    hour,
    day,
    month,
    year
}eTi;

}

class Dlt698TI : public Dlt698Proctol
{
public:
    Dlt698TI(_mTI::eTi t = _mTI::second, long_unsigned_c v = 0);


    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    _mTI::eTi getUnit() const;
    void setUnit(const _mTI::eTi &value);

    long_unsigned_c getValue() const;
    void setValue(const long_unsigned_c &value);

private:
    _mTI::eTi unit;
    long_unsigned_c value;
};

#endif // DLT698TI_H

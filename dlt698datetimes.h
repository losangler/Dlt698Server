#ifndef DLT698DATETIMES_H
#define DLT698DATETIMES_H

#include "dlt698proctol.h"

class Dlt698DateTimeS : public Dlt698Proctol
{
public:
    Dlt698DateTimeS();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    long_unsigned_c getYear() const;
    void setYear(const long_unsigned_c &value);

    unsigned_c getMonth() const;
    void setMonth(const unsigned_c &value);

    unsigned_c getDay() const;
    void setDay(const unsigned_c &value);

    unsigned_c getHour() const;
    void setHour(const unsigned_c &value);

    unsigned_c getMinute() const;
    void setMinute(const unsigned_c &value);

    unsigned_c getSecond() const;
    void setSecond(const unsigned_c &value);

    void setDateTimeS(timeval& tv);
private:
    long_unsigned_c year;

    BYTE size = 5;

    unsigned_c month;
    unsigned_c day;
    unsigned_c hour;
    unsigned_c minute;
    unsigned_c second;

    // DltObject interface
public:
    string toString();
};

#endif // DLT698DATETIMES_H

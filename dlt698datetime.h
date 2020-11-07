#ifndef DLT698DATETIME_H
#define DLT698DATETIME_H

#include <time.h>
#include <sys/time.h>
#include "dlt698proctol.h"

class Dlt698DateTime : public Dlt698Proctol
{
public:
    Dlt698DateTime();

    Dlt698DateTime(bool flag);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    long_unsigned_c getMilliseconds() const;
    void setMilliseconds(const long_unsigned_c &value);

    unsigned_c getSecond() const;
    void setSecond(const unsigned_c &value);

    unsigned_c getMinute() const;
    void setMinute(const unsigned_c &value);

    unsigned_c getHour() const;
    void setHour(const unsigned_c &value);

    unsigned_c getDay_of_week() const;
    void setDay_of_week(const unsigned_c &value);

    unsigned_c getDay_of_month() const;
    void setDay_of_month(const unsigned_c &value);

    unsigned_c getMonth() const;
    void setMonth(const unsigned_c &value);

    long_unsigned_c getYear() const;
    void setYear(const long_unsigned_c &value);

    void setDateTime(timeval& tv);
private:
    BYTE size = 6;
    long_unsigned_c year;
    unsigned_c month;
    unsigned_c dayOfMonth ;
    unsigned_c dayOfWeek;
    unsigned_c hour;
    unsigned_c minute;
    unsigned_c second;
    long_unsigned_c milliseconds;

    // DltObject interface
public:
    virtual string toString() override;
};

#endif // DLT698DATETIME_H

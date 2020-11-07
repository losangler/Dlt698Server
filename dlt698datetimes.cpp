#include "dlt698datetimes.h"

Dlt698DateTimeS::Dlt698DateTimeS()
{

}

void Dlt698DateTimeS::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->year);
    this->baseDecode(res, pos, (BYTE*)&this->month, this->size);
}

void Dlt698DateTimeS::encode(vector<BYTE> &res)
{
    this->baseEncode(res, this->year);
    this->baseEncode(res, (BYTE*)&this->month, this->size);
}

long_unsigned_c Dlt698DateTimeS::getYear() const
{
    return year;
}

void Dlt698DateTimeS::setYear(const long_unsigned_c &value)
{
    year = value;
}

unsigned_c Dlt698DateTimeS::getMonth() const
{
    return month;
}

void Dlt698DateTimeS::setMonth(const unsigned_c &value)
{
    month = value;
}

unsigned_c Dlt698DateTimeS::getDay() const
{
    return day;
}

void Dlt698DateTimeS::setDay(const unsigned_c &value)
{
    day = value;
}

unsigned_c Dlt698DateTimeS::getHour() const
{
    return hour;
}

void Dlt698DateTimeS::setHour(const unsigned_c &value)
{
    hour = value;
}

unsigned_c Dlt698DateTimeS::getMinute() const
{
    return minute;
}

void Dlt698DateTimeS::setMinute(const unsigned_c &value)
{
    minute = value;
}

unsigned_c Dlt698DateTimeS::getSecond() const
{
    return second;
}

void Dlt698DateTimeS::setSecond(const unsigned_c &value)
{
    second = value;
}

void Dlt698DateTimeS::setDateTimeS(timeval &tv)
{
    struct tm* gmtm = localtime(&tv.tv_sec);
    this->year = gmtm->tm_year + 1900;
    this->month = gmtm->tm_mon + 1;
    this->day = gmtm->tm_mday;
    this->hour = gmtm->tm_hour;
    this->minute = gmtm->tm_min;
    this->second = gmtm->tm_sec;
}

string Dlt698DateTimeS::toString()
{
    string t = "";
    t += to_string(this->year) + "-" + to_string(this->month) + "-" + to_string(this->day) + " ";
    t += to_string(this->hour) + ":" + to_string(this->minute) + ":" + to_string(this->second);
    return t;
}

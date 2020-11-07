#include "dlt698datetime.h"
#include <QDebug>

Dlt698DateTime::Dlt698DateTime()
{
    memset(&this->year, 0, this->size);
}

Dlt698DateTime::Dlt698DateTime(bool flag)
{
    memset(&this->year, 0, this->size);
    timeval tv;
    gettimeofday(&tv,nullptr);
    this->setDateTime(tv);
}

void Dlt698DateTime::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->year);
    this->baseDecode(res, pos, (BYTE*)&this->month, this->size);
    this->baseDecode(res, pos, this->milliseconds);
}

void Dlt698DateTime::encode(vector<BYTE> &res)
{
    this->baseEncode(res, this->year);
    this->baseEncode(res, (BYTE*)&this->month, this->size);
    this->baseEncode(res, this->milliseconds);
}

long_unsigned_c Dlt698DateTime::getMilliseconds() const
{
    return milliseconds;
}

void Dlt698DateTime::setMilliseconds(const long_unsigned_c &value)
{
    milliseconds = value;
}

unsigned_c Dlt698DateTime::getSecond() const
{
    return second;
}

void Dlt698DateTime::setSecond(const unsigned_c &value)
{
    second = value;
}

unsigned_c Dlt698DateTime::getMinute() const
{
    return minute;
}

void Dlt698DateTime::setMinute(const unsigned_c &value)
{
    minute = value;
}

unsigned_c Dlt698DateTime::getHour() const
{
    return hour;
}

void Dlt698DateTime::setHour(const unsigned_c &value)
{
    hour = value;
}

unsigned_c Dlt698DateTime::getDay_of_week() const
{
    return dayOfWeek;
}

void Dlt698DateTime::setDay_of_week(const unsigned_c &value)
{
    dayOfWeek = value;
}

unsigned_c Dlt698DateTime::getDay_of_month() const
{
    return dayOfMonth;
}

void Dlt698DateTime::setDay_of_month(const unsigned_c &value)
{
    dayOfMonth = value;
}

unsigned_c Dlt698DateTime::getMonth() const
{
    return month;
}

void Dlt698DateTime::setMonth(const unsigned_c &value)
{
    month = value;
}

long_unsigned_c Dlt698DateTime::getYear() const
{
    return year;
}

void Dlt698DateTime::setYear(const long_unsigned_c &value)
{
    year = value;
}

void Dlt698DateTime::setDateTime(timeval &tv)
{
    struct tm* gmtm = localtime(&tv.tv_sec);
    this->year = gmtm->tm_year + 1900;
    this->month = gmtm->tm_mon + 1;
    this->dayOfMonth = gmtm->tm_mday;
//    this->dayOfWeek = (gmtm->tm_wday - 1);

//    if(this->dayOfWeek <= 0)
//        this->dayOfWeek += 7;
    this->dayOfWeek = gmtm->tm_mday;


    this->hour = gmtm->tm_hour;
    this->minute = gmtm->tm_min;
    this->second = gmtm->tm_sec;
    this->milliseconds = tv.tv_usec / 1000;
}

string Dlt698DateTime::toString()
{
    string t = "";
    t += to_string(this->year) + "-" + to_string(this->month) + "-" + to_string(this->dayOfMonth) + " ";
    t += to_string(this->hour) + ":" + to_string(this->minute) + ":" + to_string(this->second) + ":" + to_string(this->milliseconds);
    return t;
}

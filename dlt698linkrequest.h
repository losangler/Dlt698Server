#ifndef DLT698LINKREQUEST_H
#define DLT698LINKREQUEST_H

#include "dlt698proctol.h"
#include "dlt698piidacd.h"
#include "dlt698datetime.h"

namespace _mLinkRequest {

typedef enum LinkRequestType
{
    l_login=0,
    l_heartskip,
    l_exit

}eReqTyp;

}

class Dlt698LinkRequest : public Dlt698Proctol
{
public:
    Dlt698LinkRequest();

    // DltObject interface
public:
    string toString();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    shared_ptr<Dlt698PiidAcd> getPiid() const;
    void setPiid(const shared_ptr<Dlt698PiidAcd> &value);

    _mLinkRequest::eReqTyp getSevType() const;
    void setSevType(const _mLinkRequest::eReqTyp &value);

    long_unsigned_c getHeartcycle() const;
    void setHeartcycle(const long_unsigned_c &value);

    shared_ptr<Dlt698DateTime> getReqtime() const;
    void setReqtime(const shared_ptr<Dlt698DateTime> &value);

private:
    shared_ptr<Dlt698PiidAcd> piid;
    _mLinkRequest::eReqTyp sevType;
    long_unsigned_c heartcycle;
    shared_ptr<Dlt698DateTime> reqtime;
};

#endif // DLT698LINKREQUEST_H

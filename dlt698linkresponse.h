#ifndef DLT698LINKRESPONSE_H
#define DLT698LINKRESPONSE_H

#include "dlt698datetime.h"
#include "dlt698piid.h"

class Dlt698LinkResponse : public Dlt698Proctol
{
public:
    Dlt698LinkResponse();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    shared_ptr<Dlt698Piid> getPiid() const;
    void setPiid(const shared_ptr<Dlt698Piid> &value);

    shared_ptr<Dlt698DateTime> getRequestTime() const;
    void setRequestTime(const shared_ptr<Dlt698DateTime> &value);

    shared_ptr<Dlt698DateTime> getReceiveTime() const;
    void setReceiveTime(const shared_ptr<Dlt698DateTime> &value);

    shared_ptr<Dlt698DateTime> getResponseTime() const;
    void setResponseTime(const shared_ptr<Dlt698DateTime> &value);

    BYTE getClock() const;
    void setClock(const BYTE clock);

    BYTE getRslt() const;
    void setRslt(const BYTE rslt);

    BYTE getRes() const;
    void setRes(const BYTE res);
private:
    shared_ptr<Dlt698Piid> piid;
    struct _Result{
        BYTE rslt:2;//0：成功，1：地址重复，2：非法设备，3：容量不足，其它值：保留。
        BYTE res:5;
        BYTE clock:1;//时钟可信标志 0：不可信，1：可信。
    }result;
    shared_ptr<Dlt698DateTime> requestTime;
    shared_ptr<Dlt698DateTime> receiveTime;
    shared_ptr<Dlt698DateTime> responseTime;
};

#endif // DLT698LINKRESPONSE_H

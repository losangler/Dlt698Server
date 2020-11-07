#ifndef DLT698CONNECTREQUEST_H
#define DLT698CONNECTREQUEST_H

#include "dlt698protocolconformance.h"
#include "dlt698functionconformance.h"
#include "dlt698piid.h"
#include "dlt698connectmechanisminfo.h"

class Dlt698ConnectRequest : public Dlt698Proctol
{
public:
    Dlt698ConnectRequest();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    shared_ptr<Dlt698Piid> getPiid() const;
    void setPiid(const shared_ptr<Dlt698Piid> &value);

    long_unsigned_c getProtver() const;
    void setProtver(const long_unsigned_c &value);

    shared_ptr<Dlt698ProtocolConformance> getProtconf() const;
    void setProtconf(const shared_ptr<Dlt698ProtocolConformance> &value);

    shared_ptr<Dlt698FunctionConformance> getFunconf() const;
    void setFunconf(const shared_ptr<Dlt698FunctionConformance> &value);

    long_unsigned_c getClisndframemaxsize() const;
    void setClisndframemaxsize(const long_unsigned_c &value);

    long_unsigned_c getClircvframemaxsize() const;
    void setClircvframemaxsize(const long_unsigned_c &value);

    unsigned_c getClircvframemaxwindow() const;
    void setClircvframemaxwindow(const unsigned_c &value);

    long_unsigned_c getCliapdumaxsize() const;
    void setCliapdumaxsize(const long_unsigned_c &value);

    double_long_unsigned_c getConnecttimeout() const;
    void setConnecttimeout(const double_long_unsigned_c &value);

    shared_ptr<Dlt698ConnectMechanismInfo> getMechanisminfo() const;
    void setMechanisminfo(const shared_ptr<Dlt698ConnectMechanismInfo> &value);

private:
    shared_ptr<Dlt698Piid> piid;//服务序号-优先级
    long_unsigned_c protver;//期望的应用层协议版本号
    shared_ptr<Dlt698ProtocolConformance> protconf;//期望的协议一致性块
    shared_ptr<Dlt698FunctionConformance> funconf;//期望的功能一致性块
    long_unsigned_c clisndframemaxsize;//客户机发送帧最大尺寸
    long_unsigned_c clircvframemaxsize;//客户机接收帧最大尺寸
    unsigned_c clircvframemaxwindow;//客户机接收帧最大窗口尺寸
    long_unsigned_c cliapdumaxsize;//客户机最大可处理APDU尺寸
    double_long_unsigned_c connecttimeout;//期望的应用连接超时时间
    shared_ptr<Dlt698ConnectMechanismInfo> mechanisminfo;//认证请求对象
};

#endif // DLT698CONNECTREQUEST_H

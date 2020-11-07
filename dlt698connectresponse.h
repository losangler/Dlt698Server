#ifndef DLT698CONNECTRESPONSE_H
#define DLT698CONNECTRESPONSE_H

#include <array>
#include "dlt698protocolconformance.h"
#include "dlt698functionconformance.h"
#include "dlt698piid.h"
#include "dlt698connectresponseinfo.h"

namespace _ConnectResponse {

class FactoryVersion : public Dlt698Proctol
{
public:
    FactoryVersion() {}

    void setFactoryCodeById(const size_t &id, const visible_string_c &value);
    visible_string_c getFactoryCodeById(size_t &id) const;

    void setSoftWareverById(const size_t &id, const visible_string_c &value);
    visible_string_c getSoftWareverById(const size_t &id) const;

    void setSoftWareDateById(const size_t &id, const visible_string_c &value);
    visible_string_c getSoftWareDateById(const size_t &id) const;

    void setHardWareverById(const size_t &id, const visible_string_c &value);
    visible_string_c getHardWareverById(const size_t &id) const;

    void setHardWareDateById(const size_t &id, const visible_string_c &value);
    visible_string_c getHardWareDateById(const size_t &id) const;

    void setFactoryExtentById(const size_t &id, const visible_string_c &value);
    visible_string_c getFactoryExtentById(const size_t &id) const;

private:
    array<visible_string_c, 4> factorycode{};//厂商代码
    array<visible_string_c, 4> softwarever{};//软件版本号
    array<visible_string_c, 6> softwaredate{};//软件版本日期
    array<visible_string_c, 4> hardwarever{};//硬件版本号
    array<visible_string_c, 6> hardwaredate{};//硬件版本日期
    array<visible_string_c, 8> factoryextent{};//厂家扩展信息

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);
};

}

class Dlt698ConnectResponse : public Dlt698Proctol
{
public:
    Dlt698ConnectResponse();

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


    shared_ptr<_ConnectResponse::FactoryVersion> getFactoryver() const;
    void setFactoryver(const shared_ptr<_ConnectResponse::FactoryVersion> &value);

    shared_ptr<Dlt698ConnectResponseInfo> getResponseInfo() const;
    void setResponseInfo(const shared_ptr<Dlt698ConnectResponseInfo> &value);

private:
    shared_ptr<Dlt698Piid> piid;
    shared_ptr<_ConnectResponse::FactoryVersion> factoryver;//服务器厂商版本信息
    long_unsigned_c protver;//商定的应用层协议版本号
    shared_ptr<Dlt698ProtocolConformance> protconf;//商定的协议一致性块
    shared_ptr<Dlt698FunctionConformance> funconf;//商定的功能一致性块
    long_unsigned_c clisndframemaxsize;//服务器发送帧最大尺寸
    long_unsigned_c clircvframemaxsize;//服务器接收帧最大尺寸
    unsigned_c clircvframemaxwindow;//服务器接收帧最大窗口尺寸
    long_unsigned_c cliapdumaxsize;//服务器最大可处理APDU尺寸
    double_long_unsigned_c connecttimeout;//商定的应用连接超时时间
    shared_ptr<Dlt698ConnectResponseInfo> responseInfo;//连接响应对象

};

#endif // DLT698CONNECTRESPONSE_H

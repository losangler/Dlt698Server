#ifndef DLT698CONNECTRESPONSEINFO_H
#define DLT698CONNECTRESPONSEINFO_H

#include "dlt698proctol.h"
#include "dlt698randnum.h"

namespace ConnectResponseInfo {

typedef enum _eConnectResult
{
    _connect=0,//允许建立应用连接     （0），
    _password_err,//密码错误             （1），
    _rsadecry_err,//对称解密错误         （2），
    _dsadecry_err,//非对称解密错误       （3），
    _signed_err,//签名错误             （4），
    _protver_err,//协议版本不匹配       （5），
    _other=255//其他错误             （255）

}eConnectResult;//认证结果      ConnectResult

class SecurityData : public Dlt698Proctol
{
private:
    shared_ptr<Dlt698RandNum> rn;//服务器随机数    RN，

    BYTE num;
    vector<Octet_string_c> signate;	//服务器签名信息  octet-string

public:
    SecurityData();

    vector<Octet_string_c> getSignate() const;
    void setSignate(const vector<Octet_string_c> &value);

    shared_ptr<Dlt698RandNum> getRn() const;
    void setRn(const shared_ptr<Dlt698RandNum> &value);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

};

}

class Dlt698ConnectResponseInfo : public Dlt698Proctol
{
public:

    Dlt698ConnectResponseInfo(ConnectResponseInfo::eConnectResult r = ConnectResponseInfo::_connect);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    ConnectResponseInfo::eConnectResult getResult() const;
    void setResult(const ConnectResponseInfo::eConnectResult &value);

    vector<shared_ptr<ConnectResponseInfo::SecurityData> > getSecurData() const;
    void setSecurData(const vector<shared_ptr<ConnectResponseInfo::SecurityData> > &value);

private:
    ConnectResponseInfo::eConnectResult result;

    BYTE num;
    vector<shared_ptr<ConnectResponseInfo::SecurityData> > securData; ////认证附加信息  SecurityData  OPTIONAL
};

#endif // DLT698CONNECTRESPONSEINFO_H

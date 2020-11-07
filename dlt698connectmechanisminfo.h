#ifndef DLT698CONNECTMECHANISMINFO_H
#define DLT698CONNECTMECHANISMINFO_H

#include "dlt698proctol.h"

namespace ConnectMechanismInfo {
typedef enum  SecurityType
{
    _NullSecurity=0,//公共连接    [0]
    _PasswordSecurity=1, //一般密码    [1]
    _SymmetrySecurity=2,//对称加密    [2]
    _SignatureSecurity=3 //数字签名    [3]
}eSecurTyp;

class ConnectSecurity : public Dlt698Proctol
{
public:
    ConnectSecurity() {}

    eSecurTyp getSevType() const;

private:
    eSecurTyp sevType = _NullSecurity;
};

class NullSecurity : public ConnectSecurity
{
public:
    NullSecurity() {}

private:
    eSecurTyp sevType = _NullSecurity;
};

class PasswordSecurity : public ConnectSecurity
{
public:
    PasswordSecurity() {}

private:
    eSecurTyp sevType = _PasswordSecurity;
    BYTE num;
    vector<visible_string_c> password;

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);
    BYTE getNum() const;
    void setNum(const BYTE &value);
    vector<visible_string_c> getPassword() const;
    void setPassword(const vector<visible_string_c> &value);
};

class SymmetrySecurity : public ConnectSecurity
{
public:
    SymmetrySecurity() {}

private:
    eSecurTyp sevType = _SymmetrySecurity;
    BYTE num1;
    vector<Octet_string_c> scrtext;//密文
    BYTE num2;
    vector<Octet_string_c> clisign;//客户机签名

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);
    BYTE getNum1() const;
    void setNum1(const BYTE &value);
    vector<Octet_string_c> getScrtext() const;
    void setScrtext(const vector<Octet_string_c> &value);
    BYTE getNum2() const;
    void setNum2(const BYTE &value);
    vector<Octet_string_c> getClisign() const;
    void setClisign(const vector<Octet_string_c> &value);
};

class SignatureSecurity : public SymmetrySecurity
{
public:
    SignatureSecurity() {}

private:
    eSecurTyp sevType = _SignatureSecurity;
};

}

class Dlt698ConnectMechanismInfo : public Dlt698Proctol
{
public:
    Dlt698ConnectMechanismInfo(ConnectMechanismInfo::eSecurTyp type = ConnectMechanismInfo::_NullSecurity);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    ConnectMechanismInfo::eSecurTyp getSevType() const;
    void setSevType(const ConnectMechanismInfo::eSecurTyp &value);

    shared_ptr<ConnectMechanismInfo::ConnectSecurity> getSecurity() const;
    void setSecurity(const shared_ptr<ConnectMechanismInfo::ConnectSecurity> &value);

private:
    ConnectMechanismInfo::eSecurTyp sevType;
    shared_ptr<ConnectMechanismInfo::ConnectSecurity> Security;
};

#endif // DLT698CONNECTMECHANISMINFO_H

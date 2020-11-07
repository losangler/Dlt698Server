#include "dlt698connectmechanisminfo.h"

using namespace ConnectMechanismInfo;

Dlt698ConnectMechanismInfo::Dlt698ConnectMechanismInfo(eSecurTyp type)
    : sevType(type)
{
    this->Security = shared_ptr<ConnectSecurity>(new ConnectSecurity());
}

void Dlt698ConnectMechanismInfo::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->sevType, sizeof(BYTE));
    switch(this->sevType)
    {
    case _NullSecurity:
        this->Security = shared_ptr<NullSecurity>(new NullSecurity());
        break;
    case _PasswordSecurity:
        this->Security = shared_ptr<PasswordSecurity>(new PasswordSecurity());
        break;
    case _SymmetrySecurity:
        this->Security = shared_ptr<SymmetrySecurity>(new SymmetrySecurity());
        break;
    case _SignatureSecurity:
        this->Security = shared_ptr<SignatureSecurity>(new SignatureSecurity());
        break;
    default:
        this->Security = shared_ptr<ConnectSecurity>(new ConnectSecurity());
        break;
    }
    this->Security->decode(res, pos);
}

void Dlt698ConnectMechanismInfo::encode(vector<BYTE> &res)
{
    this->sevType = this->Security->getSevType();
    this->baseEncode(res, (BYTE)this->sevType);
    this->Security->encode(res);
}

eSecurTyp Dlt698ConnectMechanismInfo::getSevType() const
{
    return this->Security->getSevType();
}

void Dlt698ConnectMechanismInfo::setSevType(const eSecurTyp &value)
{
    sevType = value;
}

shared_ptr<ConnectSecurity> Dlt698ConnectMechanismInfo::getSecurity() const
{
    return Security;
}

void Dlt698ConnectMechanismInfo::setSecurity(const shared_ptr<ConnectSecurity> &value)
{
    Security = value;
}

BYTE PasswordSecurity::getNum() const
{
    return this->password.size();
}

void PasswordSecurity::setNum(const BYTE &value)
{
    num = value;
}

vector<visible_string_c> PasswordSecurity::getPassword() const
{
    return password;
}

void PasswordSecurity::setPassword(const vector<visible_string_c> &value)
{
    password = value;
}

void PasswordSecurity::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->num);
    this->password.resize(this->num, 0);
    for(auto &k : this->password)
    {
        BYTE buff;
        this->baseDecode(res, pos, buff);
        k = buff;
    }
}

void PasswordSecurity::encode(vector<BYTE> &res)
{
    this->num = this->password.size();
    this->baseEncode(res, this->num);
    for(auto &k : this->password)
    {
        BYTE buff = k;
        this->baseEncode(res, buff);
    }
}

BYTE SymmetrySecurity::getNum1() const
{
    return this->scrtext.size();
}

void SymmetrySecurity::setNum1(const BYTE &value)
{
    num1 = value;
}

vector<Octet_string_c> SymmetrySecurity::getScrtext() const
{
    return scrtext;
}

void SymmetrySecurity::setScrtext(const vector<Octet_string_c> &value)
{
    scrtext = value;
}

BYTE SymmetrySecurity::getNum2() const
{
    return this->clisign.size();
}

void SymmetrySecurity::setNum2(const BYTE &value)
{
    num2 = value;
}

vector<Octet_string_c> SymmetrySecurity::getClisign() const
{
    return clisign;
}

void SymmetrySecurity::setClisign(const vector<Octet_string_c> &value)
{
    clisign = value;
}

void SymmetrySecurity::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->num1);
    this->scrtext.resize(this->num1, 0);
    for(auto &k : this->scrtext)
    {
        this->baseDecode(res, pos, k);
    }
    this->baseDecode(res, pos, this->num2);
    this->clisign.resize(this->num2, 0);
    for(auto &k : this->clisign)
    {
        this->baseDecode(res, pos, k);
    }
}

void SymmetrySecurity::encode(vector<BYTE> &res)
{
    this->num1 = this->scrtext.size();
    this->baseEncode(res, this->num1);
    for(auto &k : this->scrtext)
    {
        this->baseEncode(res, k);
    }
    this->num2 = this->clisign.size();
    this->baseEncode(res, this->num2);
    for(auto &k : this->clisign)
    {
        this->baseEncode(res, k);
    }
}

eSecurTyp ConnectSecurity::getSevType() const
{
    return this->sevType;
}

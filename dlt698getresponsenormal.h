#ifndef DLT698GETRESPONSENORMAL_H
#define DLT698GETRESPONSENORMAL_H

#include "dlt698piidacd.h"
#include "dlt698oad.h"
#include "dlt698data.h"
#include <QDebug>

namespace Dlt698 {

enum eGetResult
{
    _DAR=0,
    _Data=1
};

struct Get_Result{
    eDAR dar;
    shared_ptr<Dlt698Data> data;

    Get_Result()
    {
        data = shared_ptr<Dlt698Data>(new Dlt698Data());
    }

    ~Get_Result()
    {

    }
};

class ResultNormal : public Dlt698Proctol
{
public:
    ResultNormal();
    shared_ptr<Dlt698Oad> getOad() const;
    void setOad(const shared_ptr<Dlt698Oad> &value);

    shared_ptr<Get_Result> getResult() const;
    void setResult(const shared_ptr<Get_Result> &value);

    eGetResult getResultType() const;
    void setResultType(const eGetResult &value);

private:
    shared_ptr<Dlt698Oad> oad;//对象属性描述符     OAD，
    eGetResult resultType;
    shared_ptr<Get_Result> result;

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

};

}

class Dlt698GetResponseNormal : public Dlt698Proctol
{
public:
    Dlt698GetResponseNormal();

    shared_ptr<Dlt698PiidAcd> getPiid() const;
    void setPiid(const shared_ptr<Dlt698PiidAcd> &value);
    shared_ptr<Dlt698::ResultNormal> getResult() const;
    void setResult(const shared_ptr<Dlt698::ResultNormal> &value);

private:
    shared_ptr<Dlt698PiidAcd> piid;
    shared_ptr<Dlt698::ResultNormal> result;

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

};

#endif // DLT698GETRESPONSENORMAL_H

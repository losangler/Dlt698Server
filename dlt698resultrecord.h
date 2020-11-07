#ifndef DLT698RESULTRECORD_H
#define DLT698RESULTRECORD_H

#include "dlt698road.h"
#include "dlt698rcsd.h"
#include "dlt698data.h"

namespace _mResultRecod {

enum eResponseData
{
    _DAR=0,
    _RecordRow=1

};

}

class Dlt698ResultRecord : public Dlt698Proctol
{
public:
    Dlt698ResultRecord(_mResultRecod::eResponseData data = _mResultRecod::_RecordRow, eDAR d = _Succ);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    shared_ptr<Dlt698Oad> getOad() const;
    void setOad(const shared_ptr<Dlt698Oad> &value);

    shared_ptr<Dlt698Rcsd> getRcsd() const;
    void setRcsd(const shared_ptr<Dlt698Rcsd> &value);

    _mResultRecod::eResponseData getChoiceRespDat() const;
    void setChoiceRespDat(const _mResultRecod::eResponseData &value);

    eDAR getDar() const;
    void setDar(const eDAR &value);

    vector<shared_ptr<Dlt698Data> > getPDat() const;
    void setPDat(const vector<shared_ptr<Dlt698Data> > &value);

    void addData(shared_ptr<Dlt698Data> dat);
private:
    shared_ptr<Dlt698Oad> oad;//对象属性描述符     OAD，

    shared_ptr<Dlt698Rcsd> rcsd;//一行记录N列属性描述符   RCSD

    _mResultRecod::eResponseData choiceRespDat;

    eDAR dar;

    vector<shared_ptr<Dlt698Data> > pDat;

    // DltObject interface
public:
    string toString() override;
};

#endif // DLT698RESULTRECORD_H

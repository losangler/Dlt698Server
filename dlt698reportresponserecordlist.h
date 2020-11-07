#ifndef DLT698REPORTRESPONSERECORDLIST_H
#define DLT698REPORTRESPONSERECORDLIST_H

#include "dlt698piid.h"
#include "dlt698oad.h"

class Dlt698ReportResponseRecordList : public Dlt698Proctol
{
public:
    Dlt698ReportResponseRecordList();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    shared_ptr<Dlt698Piid> getPiid() const;
    void setPiid(const shared_ptr<Dlt698Piid> &value);

    BYTE getNum() const;
    void setNum(const BYTE &value);

    vector<shared_ptr<Dlt698Oad> > getOads() const;
    void setOads(const vector<shared_ptr<Dlt698Oad> > &value);

    void addOad(const shared_ptr<Dlt698Oad> &oad);
    shared_ptr<Dlt698Oad> getOad(BYTE id) const;
private:
    shared_ptr<Dlt698Piid> piid;
    BYTE num;
    vector<shared_ptr<Dlt698Oad> > oads;
};

#endif // DLT698REPORTRESPONSERECORDLIST_H

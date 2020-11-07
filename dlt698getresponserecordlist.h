#ifndef DLT698GETRESPONSERECORDLIST_H
#define DLT698GETRESPONSERECORDLIST_H

#include "dlt698resultrecord.h"
#include "dlt698piidacd.h"

class Dlt698GetResponseRecordList : public Dlt698Proctol
{
public:
    Dlt698GetResponseRecordList();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;
    string toString() override;

    shared_ptr<Dlt698PiidAcd> getPiid() const;
    void setPiid(const shared_ptr<Dlt698PiidAcd> &value);

    vector<shared_ptr<Dlt698ResultRecord> > getPaRsltrec() const;
    void setPaRsltrec(const vector<shared_ptr<Dlt698ResultRecord> > &value);

    void addRecord(shared_ptr<Dlt698ResultRecord> record);
    shared_ptr<Dlt698ResultRecord> getRecordById(size_t id);
private:
    shared_ptr<Dlt698PiidAcd> piid;
    BYTE num;
    vector<shared_ptr<Dlt698ResultRecord> > paRsltrec;

};

#endif // DLT698GETRESPONSERECORDLIST_H

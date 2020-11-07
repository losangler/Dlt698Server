#ifndef DLT698GETRESPONSERECORD_H
#define DLT698GETRESPONSERECORD_H

#include "dlt698resultrecord.h"
#include "dlt698piidacd.h"

class Dlt698GetResponseRecord : public Dlt698Proctol
{
public:
    Dlt698GetResponseRecord();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    shared_ptr<Dlt698PiidAcd> getPiid() const;
    void setPiid(const shared_ptr<Dlt698PiidAcd> &value);

    shared_ptr<Dlt698ResultRecord> getRecord() const;
    void setRecord(const shared_ptr<Dlt698ResultRecord> &value);

private:
    shared_ptr<Dlt698PiidAcd> piid;
    shared_ptr<Dlt698ResultRecord> record;
};

#endif // DLT698GETRESPONSERECORD_H

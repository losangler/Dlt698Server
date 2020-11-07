#ifndef DLT698GETRESPONSENORMALLIST_H
#define DLT698GETRESPONSENORMALLIST_H

#include "dlt698getresponsenormal.h"

class Dlt698GetResponseNormalList : public Dlt698Proctol
{
public:
    Dlt698GetResponseNormalList();

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

    shared_ptr<Dlt698PiidAcd> getPiid() const;
    void setPiid(const shared_ptr<Dlt698PiidAcd> &value);

    vector<shared_ptr<Dlt698::ResultNormal> > getResults() const;
    void setResults(const vector<shared_ptr<Dlt698::ResultNormal> > &value);

private:
    shared_ptr<Dlt698PiidAcd> piid;
    BYTE num;
    vector<shared_ptr<Dlt698::ResultNormal> > results;
};

#endif // DLT698GETRESPONSENORMALLIST_H

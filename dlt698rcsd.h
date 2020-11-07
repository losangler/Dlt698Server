#ifndef DLT698RCSD_H
#define DLT698RCSD_H

#include "dlt698csd.h"

class Dlt698Rcsd : public Dlt698Proctol
{
public:
    Dlt698Rcsd(BYTE n = 0);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;
    string toString() override;

    BYTE getNum() const;
    void setNum(const BYTE &value);

    vector<shared_ptr<Dlt698Csd> > getPCsd() const;
    void setPCsd(const vector<shared_ptr<Dlt698Csd> > &value);

    void addCsd(shared_ptr<Dlt698Csd> csd);
private:
    BYTE num;
    vector<shared_ptr<Dlt698Csd> > pCsd;

};

#endif // DLT698RCSD_H

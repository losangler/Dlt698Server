#ifndef DLT698DATA_H
#define DLT698DATA_H

#include "dlt698proctol.h"
#include "memory"

class Dlt698Data : public Dlt698Proctol
{
public:
    Dlt698Data(eDataType type = t_null);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    eDataType getETyp() const;
    void setETyp(const eDataType &value);

    vector<BYTE> getByDat() const;
    void getByDat(void *dat, size_t &pos, size_t size);

    void setByDat(const vector<BYTE> &value);
    void setByDat(const void *dat, size_t size);

    void addChild(shared_ptr<Dlt698Data> child);
    shared_ptr<Dlt698Data> getChild(int id) const;

    void vectorCopy(const vector<BYTE> &res, size_t &pos, vector<BYTE> &aim, size_t size);
    size_t getChildsSize() const;
private:
    eDataType eTyp;
    vector<BYTE> byDat;
    vector<shared_ptr<Dlt698Data> > childs;


    // DltObject interface
public:
    string toString() override;
};

#endif // DLT698DATA_H

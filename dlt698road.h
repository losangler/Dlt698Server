#ifndef DLT698ROAD_H
#define DLT698ROAD_H

#include <memory>
#include "dlt698oad.h"

class Dlt698Road : public Dlt698Proctol
{
public:
    Dlt698Road(BYTE n = 0);

    ~Dlt698Road();
    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    shared_ptr<Dlt698Oad> getOad() const;
    void setOad(shared_ptr<Dlt698Oad> value);

    BYTE getNum() const;
    void setNum(const BYTE &value);

    vector<shared_ptr<Dlt698Oad> > getPOAD() const;
    void setPOAD(const vector<shared_ptr<Dlt698Oad> > &value);

    void addOAD(shared_ptr<Dlt698Oad> value);
private:
    shared_ptr<Dlt698Oad> oad;
    BYTE num;
    vector<shared_ptr<Dlt698Oad>> pOAD;
};

#endif // DLT698ROAD_H

#ifndef DLT698TIMETAG_H
#define DLT698TIMETAG_H

#include "dlt698ti.h"
#include "dlt698datetimes.h"
#include <memory>

class Dlt698TimeTag : public Dlt698Proctol
{
public:
    Dlt698TimeTag();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    shared_ptr<Dlt698DateTimeS> getMark() const;
    void setMark(const shared_ptr<Dlt698DateTimeS> &value);

    shared_ptr<Dlt698TI> getDalay() const;
    void setDalay(const shared_ptr<Dlt698TI> &value);

private:
    shared_ptr<Dlt698DateTimeS> mark;
    shared_ptr<Dlt698TI> dalay;
};

#endif // DLT698TIMETAG_H

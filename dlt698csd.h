#ifndef DLT698CSD_H
#define DLT698CSD_H

#include "dlt698oad.h"
#include "dlt698road.h"

namespace Csd {

enum eCSD
{
    _OAD=0,
    _ROAD=1
};

}

class Dlt698Csd : public Dlt698Proctol
{
public:
    Dlt698Csd(Csd::eCSD csd = Csd::_OAD);

    ~Dlt698Csd();
    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    Csd::eCSD getECsd() const;
    void setECsd(const Csd::eCSD &value);

    shared_ptr<Dlt698Proctol> getUscd() const;
    void setUscd(shared_ptr<Dlt698Proctol> value);

private:
    Csd::eCSD eCsd;

    shared_ptr<Dlt698Proctol> uscd;

    // DltObject interface
public:
    string toString() override;
};

#endif // DLT698CSD_H

#ifndef DLT698CLIENTAPDU_H
#define DLT698CLIENTAPDU_H

#include "dlt698proctol.h"
#include "dlt698timetag.h"

class Dlt698ClientApdu : public Dlt698Proctol
{
public:
    Dlt698ClientApdu(eClientAPDU type = ConnectRequest, bool_c tagExist = false);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    eClientAPDU getSevType() const;
    void setSevType(const eClientAPDU &value);

    vector<BYTE> getBody() const;
    void setBody(const vector<BYTE> &value);

    shared_ptr<Dlt698TimeTag> getTimeTag() const;
    void setTimeTag(const shared_ptr<Dlt698TimeTag> &value);

    bool_c getTimeTagExist() const;
    void setTimeTagExist(const bool_c &value);

private:
    eClientAPDU sevType;

    vector<BYTE> body;

    bool_c timeTagExist;

    shared_ptr<Dlt698TimeTag> timeTag;

};

#endif // DLT698CLIENTAPDU_H

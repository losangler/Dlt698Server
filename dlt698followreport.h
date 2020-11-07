#ifndef DLT698FOLLOWREPORT_H
#define DLT698FOLLOWREPORT_H

#include "dlt698proctol.h"

class Dlt698FollowReport : public Dlt698Proctol
{
public:
    typedef enum _eReportType{
        resultNormal = 1,
        resultRecord = 2
    }reportType;

    Dlt698FollowReport(reportType t = resultNormal);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    reportType getType() const;
    void setType(const reportType &value);

private:
    reportType type;
};

#endif // DLT698FOLLOWREPORT_H

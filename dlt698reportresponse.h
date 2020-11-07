#ifndef DLT698REPORTRESPONSE_H
#define DLT698REPORTRESPONSE_H

#include "dlt698proctol.h"

namespace _mReportResponse {

typedef enum _eREPORTResponse
{
    ReportResponseList=1,
    ReportResponseRecordList,
    ReportResponseTransData
}eReportResponse;

}

class Dlt698ReportResponse : public Dlt698Proctol
{
public:
    Dlt698ReportResponse();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    _mReportResponse::eReportResponse getSevType() const;
    void setSevType(const _mReportResponse::eReportResponse &value);

    vector<BYTE> getBody() const;
    void setBody(const vector<BYTE> &value);

private:
    _mReportResponse::eReportResponse sevType;

    vector<BYTE> body;
};

#endif // DLT698REPORTRESPONSE_H

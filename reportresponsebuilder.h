#ifndef REPORTRESPONSEBUILDER_H
#define REPORTRESPONSEBUILDER_H

#include "clientapdubuilder.h"
#include "dlt698reportresponse.h"

namespace Dlt698 {

class ReportResponseBuilder : public ClientApduBuilder
{
public:
    ReportResponseBuilder();

    ReportResponseBuilder* responseType(const _mReportResponse::eReportResponse &value);

    ReportResponseBuilder* responseBody(const vector<BYTE> &value);

    shared_ptr<Dlt698ReportResponse> responseBuild();

    // ClientApduBuilder interface
protected:
    vector<BYTE> clientBodyBuild() override final;

    virtual vector<BYTE> responseBodyBuild();

    shared_ptr<Dlt698ReportResponse> response;
};

}

#endif // REPORTRESPONSEBUILDER_H

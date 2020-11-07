#include "reportresponsebuilder.h"

using namespace Dlt698;

ReportResponseBuilder::ReportResponseBuilder()
{
    this->response = shared_ptr<Dlt698ReportResponse>(new Dlt698ReportResponse());
    this->cliApdu->setSevType(ReportResponse);

    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu->getCtrl();
    ctrl->setPRM(0);
}

ReportResponseBuilder *ReportResponseBuilder::responseType(const _mReportResponse::eReportResponse &value)
{
    this->response->setSevType(value);
    return this;
}

ReportResponseBuilder *ReportResponseBuilder::responseBody(const vector<BYTE> &value)
{
    this->response->setBody(value);
    return this;
}

shared_ptr<Dlt698ReportResponse> ReportResponseBuilder::responseBuild()
{
    this->response->setBody(this->responseBodyBuild());
    return this->response;
}

vector<BYTE> ReportResponseBuilder::clientBodyBuild()
{
    return this->responseBuild()->toBytes();
}

vector<BYTE> ReportResponseBuilder::responseBodyBuild()
{
    return this->response->getBody();
}

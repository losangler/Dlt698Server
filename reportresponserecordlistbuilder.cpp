#include "reportresponserecordlistbuilder.h"

using namespace Dlt698;

ReportResponseRecordListBuilder::ReportResponseRecordListBuilder()
{
    this->responseRecord = shared_ptr<Dlt698ReportResponseRecordList>(new Dlt698ReportResponseRecordList());
    this->response->setSevType(_mReportResponse::ReportResponseRecordList);
}

ReportResponseRecordListBuilder *ReportResponseRecordListBuilder::piid(const shared_ptr<Dlt698Piid> &value)
{
    this->responseRecord->setPiid(value);
    return this;
}

ReportResponseRecordListBuilder *ReportResponseRecordListBuilder::oads(const vector<shared_ptr<Dlt698Oad> > &value)
{
    this->responseRecord->setOads(value);
    return this;
}

ReportResponseRecordListBuilder *ReportResponseRecordListBuilder::oad(const shared_ptr<Dlt698Oad> &value)
{
    this->responseRecord->addOad(value);
    return this;
}

shared_ptr<Dlt698ReportResponseRecordList> ReportResponseRecordListBuilder::responseRecordBuild()
{
    return this->responseRecord;
}

vector<BYTE> ReportResponseRecordListBuilder::responseBodyBuild()
{
    return this->responseRecordBuild()->toBytes();
}

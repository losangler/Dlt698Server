#include "reportnotificationrecordlistbuilder.h"

using namespace Dlt698;

ReportNotificationRecordListBuilder::ReportNotificationRecordListBuilder()
{
    this->records = shared_ptr<Dlt698GetResponseRecordList>(new Dlt698GetResponseRecordList());
    this->notification->setSevType(_mReportNotification::ReportNotificationRecordList);
}

ReportNotificationRecordListBuilder *ReportNotificationRecordListBuilder::piid(const shared_ptr<Dlt698PiidAcd> &value)
{
    this->records->setPiid(value);
    return this;
}

ReportNotificationRecordListBuilder *ReportNotificationRecordListBuilder::resultRecords(const vector<shared_ptr<Dlt698ResultRecord> > &value)
{
    this->records->setPaRsltrec(value);
    return this;
}

shared_ptr<Dlt698GetResponseRecordList> ReportNotificationRecordListBuilder::recordsBuild()
{
    return this->records;
}

vector<BYTE> ReportNotificationRecordListBuilder::notificationBodyBuild()
{
    return this->recordsBuild()->toBytes();
}

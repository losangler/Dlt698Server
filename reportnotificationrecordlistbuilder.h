#ifndef REPORTNOTIFICATIONRECORDLISTBUILDER_H
#define REPORTNOTIFICATIONRECORDLISTBUILDER_H

#include "reportnotificationbuilder.h"
#include "dlt698getresponserecordlist.h"

namespace Dlt698 {

class ReportNotificationRecordListBuilder : public ReportNotificationBuilder
{
public:
    ReportNotificationRecordListBuilder();

    ReportNotificationRecordListBuilder* piid(const shared_ptr<Dlt698PiidAcd> &value);

    ReportNotificationRecordListBuilder* resultRecords(const vector<shared_ptr<Dlt698ResultRecord> > &value);

    shared_ptr<Dlt698GetResponseRecordList> recordsBuild();

    // ReportNotificationBuilder interface
protected:
    vector<BYTE> notificationBodyBuild() override final;

    shared_ptr<Dlt698GetResponseRecordList> records;
};


}

#endif // REPORTNOTIFICATIONRECORDLISTBUILDER_H

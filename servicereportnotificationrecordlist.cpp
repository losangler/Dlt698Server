#include "servicereportnotificationrecordlist.h"
#include "dlt698servicefactory.h"
#include "dlt698reportnotification.h"
#include "dlt698serverapdu.h"
#include "dlt698getresponserecordlist.h"
#include <QDebug>

using namespace Dlt698;

ServiceReportNotificationRecordList::ServiceReportNotificationRecordList()
{
    WORD type = this->getServiceType(ReportNotification, _mReportNotification::ReportNotificationRecordList);
    Dlt698ServiceFactory::instance()->setService(type, this);
}

void ServiceReportNotificationRecordList::doService(Dlt698::ServiceRequest &request, Dlt698::ServiceResponse &response)
{
    qDebug() << "ReportNotificationList: 88 02";

    size_t pos;
    Dlt698ServerApdu server;
    pos = 0;
    server.decode(request.getApdu()->getByASDU(), pos);

    Dlt698ReportNotification report;
    pos = 0;
    report.decode(server.getBody(), pos);

    shared_ptr<Dlt698GetResponseRecordList> res(new Dlt698GetResponseRecordList());
    pos = 0;
    res->decode(report.getBody(), pos);
    qDebug() << QString::fromStdString(res->toString());
}

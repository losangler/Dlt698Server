#include "servicereportnotificationnormallist.h"
#include "dlt698servicefactory.h"
#include "dlt698reportnotification.h"
#include "dlt698serverapdu.h"
#include "dlt698getresponsenormallist.h"
#include <QDebug>

using namespace Dlt698;

ServiceReportNotificationNormalList::ServiceReportNotificationNormalList()
{
    WORD type = this->getServiceType(ReportNotification, _mReportNotification::ReportNotificationList);
    Dlt698ServiceFactory::instance()->setService(type, this);
}

void ServiceReportNotificationNormalList::doService(ServiceRequest &request, ServiceResponse &response)
{
    qDebug() << "ReportNotificationList: 88 01";

    size_t pos;
    Dlt698ServerApdu server;
    pos = 0;
    server.decode(request.getApdu()->getByASDU(), pos);

    Dlt698ReportNotification report;
    pos = 0;
    report.decode(server.getBody(), pos);

    shared_ptr<Dlt698GetResponseNormalList> res(new Dlt698GetResponseNormalList());
    pos = 0;
    res->decode(report.getBody(), pos);
    qDebug() << QString::fromStdString(res->toHexString());
}

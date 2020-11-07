#include "reportnotificationbuilder.h"

using namespace Dlt698;

ReportNotificationBuilder::ReportNotificationBuilder()
{
    this->notification = shared_ptr<Dlt698ReportNotification>(new Dlt698ReportNotification());
    this->srvApdu->setSevType(ReportNotification);

    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu->getCtrl();
    ctrl->setPRM(0);
}

ReportNotificationBuilder *ReportNotificationBuilder::notificationType(const _mReportNotification::eReportNotification &value)
{
    this->notification->setSevType(value);
    return this;
}

ReportNotificationBuilder *ReportNotificationBuilder::notificationBody(const vector<BYTE> &value)
{
    this->notification->setBody(value);
    return this;
}

shared_ptr<Dlt698ReportNotification> ReportNotificationBuilder::notificationBuild()
{
    this->notification->setBody(this->notificationBodyBuild());
    return this->notification;
}

vector<BYTE> ReportNotificationBuilder::serverBodyBuild()
{
    return this->notificationBuild()->toBytes();
}

vector<BYTE> ReportNotificationBuilder::notificationBodyBuild()
{
    return this->notification->getBody();
}

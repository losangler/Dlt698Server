#ifndef REPORTNOTIFICATIONBUILDER_H
#define REPORTNOTIFICATIONBUILDER_H


#include "serverapdubuilder.h"
#include "dlt698reportnotification.h"

namespace Dlt698 {

class ReportNotificationBuilder : public ServerApduBuilder
{
public:
    ReportNotificationBuilder();

    ReportNotificationBuilder* notificationType(const _mReportNotification::eReportNotification &value);

    ReportNotificationBuilder* notificationBody(const vector<BYTE> &value);

    shared_ptr<Dlt698ReportNotification> notificationBuild();

    // ServerApduBuilder interface
protected:
    vector<BYTE> serverBodyBuild() override final;

    virtual vector<BYTE> notificationBodyBuild();

    shared_ptr<Dlt698ReportNotification> notification;
};

}
#endif // REPORTNOTIFICATIONBUILDER_H

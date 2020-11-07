#ifndef MYSERVICEREPORTNOTIFICATIONLIST_H
#define MYSERVICEREPORTNOTIFICATIONLIST_H

#include "servicereportnotificationnormallist.h"
#include "dlt698getresponsenormallist.h"

class MyServiceReportNotificationList : public Dlt698::ServiceReportNotificationNormalList
{
public:
    MyServiceReportNotificationList();

    void currentPossitonTime(shared_ptr<Dlt698Apdu> apdu, shared_ptr<Dlt698GetResponseNormalList> req);

    // Dlt698Service interface
public:
    virtual void doService(Dlt698::ServiceRequest &request, Dlt698::ServiceResponse &response) override;
};

#endif // MYSERVICEREPORTNOTIFICATIONLIST_H

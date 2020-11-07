#ifndef SERVICEREPORTNOTIFICATIONNORMALLIST_H
#define SERVICEREPORTNOTIFICATIONNORMALLIST_H

#include "dlt698service.h"

namespace Dlt698 {

class ServiceReportNotificationNormalList : public Dlt698Service
{
public:
    ServiceReportNotificationNormalList();

    // Dlt698Service interface
public:
    virtual void doService(ServiceRequest &request, ServiceResponse &response) override;
};

}

#endif // SERVICEREPORTNOTIFICATIONNORMALLIST_H

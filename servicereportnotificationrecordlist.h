#ifndef SERVICEREPORTNOTIFICATIONRECORDLIST_H
#define SERVICEREPORTNOTIFICATIONRECORDLIST_H

#include "dlt698service.h"

namespace Dlt698 {

class ServiceReportNotificationRecordList : public Dlt698Service
{
public:
    ServiceReportNotificationRecordList();

    // Dlt698Service interface
public:
    virtual void doService(Dlt698::ServiceRequest &request, Dlt698::ServiceResponse &response) override;
};

}

#endif // SERVICEREPORTNOTIFICATIONRECORDLIST_H

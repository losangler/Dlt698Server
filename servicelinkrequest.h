#ifndef SERVICELINKREQUEST_H
#define SERVICELINKREQUEST_H

#include "dlt698service.h"

namespace Dlt698 {

class ServiceLinkRequest : public Dlt698Service
{
public:
    ServiceLinkRequest();

    // Dlt698Service interface
public:
    virtual void doService(ServiceRequest &request, ServiceResponse &response) override;
};

}

#endif // SERVICELINKREQUEST_H

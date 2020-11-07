#ifndef MYSERVICELINKREQUEST_H
#define MYSERVICELINKREQUEST_H

#include "servicelinkrequest.h"

class MyServiceLinkRequest : public Dlt698::ServiceLinkRequest
{
public:
    MyServiceLinkRequest();

    // Dlt698Service interface
public:
    virtual void doService(Dlt698::ServiceRequest &request, Dlt698::ServiceResponse &response) override;
};

#endif // MYSERVICELINKREQUEST_H

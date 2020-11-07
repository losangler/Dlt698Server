#ifndef DLT698SERVICE_H
#define DLT698SERVICE_H

#include "dlt698service_global.h"
#include "servicerequest.h"
#include "serviceresponse.h"

class DLT698SERVICESHARED_EXPORT Dlt698Service
{

public:
    Dlt698Service();

    virtual void doService(Dlt698::ServiceRequest &request,Dlt698::ServiceResponse &response);

    WORD getServiceType(BYTE x);

    WORD getServiceType(BYTE x, BYTE y);
};

#endif // DLT698SERVICE_H

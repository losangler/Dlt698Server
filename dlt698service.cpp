#include "dlt698service.h"
#include <QDebug>

Dlt698Service::Dlt698Service()
{

}

void Dlt698Service::doService(Dlt698::ServiceRequest &request, Dlt698::ServiceResponse &response)
{

}

WORD Dlt698Service::getServiceType(BYTE x)
{
    return x;
}

WORD Dlt698Service::getServiceType(BYTE x, BYTE y)
{
    WORD res = x;
    return (res << 8) + y;
}

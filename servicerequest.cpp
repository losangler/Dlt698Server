#include "servicerequest.h"

using namespace Dlt698;

ServiceRequest::ServiceRequest()
{
    this->apdu = shared_ptr<Dlt698Apdu>(new Dlt698Apdu());
}

ServiceRequest::~ServiceRequest()
{

}

vector<BYTE> ServiceRequest::getData() const
{
    return data;
}

void ServiceRequest::setData(const vector<BYTE> &value)
{
    data = value;
}

shared_ptr<Dlt698Apdu> ServiceRequest::getApdu() const
{
    return apdu;
}

void ServiceRequest::setApdu(const shared_ptr<Dlt698Apdu> &value)
{
    apdu = value;
}

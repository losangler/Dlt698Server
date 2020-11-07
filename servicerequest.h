#ifndef SERVICEREQUEST_H
#define SERVICEREQUEST_H

#include "dlt698apdu.h"

namespace Dlt698 {

class ServiceRequest
{
public:
    ServiceRequest();
    virtual ~ServiceRequest();

    vector<BYTE> getData() const;
    void setData(const vector<BYTE> &value);

    shared_ptr<Dlt698Apdu> getApdu() const;
    void setApdu(const shared_ptr<Dlt698Apdu> &value);

private:
    vector<BYTE> data;
    shared_ptr<Dlt698Apdu> apdu;
};

}

#endif // SERVICEREQUEST_H

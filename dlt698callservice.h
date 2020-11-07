#ifndef DLT698CALLSERVICE_H
#define DLT698CALLSERVICE_H

#include "dlt698servicefactory.h"

class Dlt698CallService : Dlt698Service
{
public:
    Dlt698CallService();
    ~Dlt698CallService();

    void decrypt(shared_ptr<Dlt698Apdu> apdu);
    Dlt698Service* findService(shared_ptr<Dlt698Apdu> apdu);

    // Dlt698Service interface
public:
    virtual void doService(Dlt698::ServiceRequest &request, Dlt698::ServiceResponse &response) override final;
};

#endif // DLT698CALLSERVICE_H

#ifndef MYSERVICERESPONSE_H
#define MYSERVICERESPONSE_H

#include "serviceresponse.h"
#include "epollevent.h"

class MyServiceResponse : public Dlt698::ServiceResponse
{
public:
    MyServiceResponse(Dlt698::EpollEvent *e = nullptr);

    ~MyServiceResponse();

    Dlt698::EpollEvent *getEvent() const;
    void setEvent(Dlt698::EpollEvent *value);

private:
    Dlt698::EpollEvent *event;
};

#endif // MYSERVICERESPONSE_H

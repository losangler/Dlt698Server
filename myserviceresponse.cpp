#include "myserviceresponse.h"

MyServiceResponse::MyServiceResponse(Dlt698::EpollEvent *e)
    : event(e)
{

}

MyServiceResponse::~MyServiceResponse()
{

}

Dlt698::EpollEvent *MyServiceResponse::getEvent() const
{
    return event;
}

void MyServiceResponse::setEvent(Dlt698::EpollEvent *value)
{
    event = value;
}

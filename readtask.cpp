#include "readtask.h"
#include "myserviceresponse.h"
#include "dlt698datetime.h"
#include <QDebug>

ReadTask::ReadTask(EpollEvent *e)
    : event(e)
{

}

ReadTask::~ReadTask()
{
    delete event;
}

void ReadTask::doTask()
{
    ServiceRequest request;
    MyServiceResponse response(this->event);
    vector<BYTE> data(event->getBuffer(), event->getBuffer() + event->getSize());
    request.setData(data);

    shared_ptr<Dlt698DateTime> revTime(new Dlt698DateTime(true));
    qDebug() << "fd =" << event->getSocket().getSockfd() << QString::fromStdString(revTime->toString());

    Dlt698CallService service;
    service.doService(request, response);

    qDebug() << QString::fromStdString(request.getApdu()->byteToString(data.data(), data.size()));
}

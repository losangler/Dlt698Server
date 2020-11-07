#include "dlt698callservice.h"
#include <QDebug>

using namespace Dlt698;

Dlt698CallService::Dlt698CallService()
{

}

Dlt698CallService::~Dlt698CallService()
{

}

void Dlt698CallService::decrypt(shared_ptr<Dlt698Apdu> apdu)
{

}

Dlt698Service *Dlt698CallService::findService(shared_ptr<Dlt698Apdu> apdu)
{
    Dlt698Service *service = nullptr;
    if(apdu->getByASDU().size() < 2)
    {
        qDebug() << "数据包过短";
        return service;
    }

    WORD type = this->getServiceType(apdu->getByASDU().at(0));
    if((service = Dlt698ServiceFactory::instance()->getService(type)) == nullptr)
    {
        type = this->getServiceType(apdu->getByASDU().at(0), apdu->getByASDU().at(1));
        if((service = Dlt698ServiceFactory::instance()->getService(type)) == nullptr)
        {
            qDebug() << "服务不存在:type =" << type;
        }
    }
    return service;
}

void Dlt698CallService::doService(ServiceRequest &request, ServiceResponse &response)
{
    if(request.getData().size() == 0)
    {
        qDebug() << "帧数据过短";
        return;
    }

    shared_ptr<Dlt698Apdu> apdu = request.getApdu();
    size_t pos = 0;
    apdu->decode(request.getData(), pos);

    if(pos == 0)
    {
        qDebug() << "帧解析失败";
        return;
    }
    qDebug() << "帧解析成功";
    this->decrypt(apdu);

    Dlt698Service *service = this->findService(apdu);
    if(service == nullptr)
    {
        return;
    }
    qDebug() << "寻找服务成功";
    service->doService(request, response);
}

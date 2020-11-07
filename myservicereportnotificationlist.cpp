#include "myservicereportnotificationlist.h"
#include "reportresponserecordlistbuilder.h"
#include "dlt698getresponsenormallist.h"
#include "dlt698reportnotification.h"
#include "dlt698serverapdu.h"
#include "myserviceresponse.h"
#include "terminalinfoservice.h"
#include "terminalservice.h"
#include "terminalentity.h"
#include <QDebug>

using namespace Dlt698;

MyServiceReportNotificationList::MyServiceReportNotificationList()
{

}

void MyServiceReportNotificationList::currentPossitonTime(shared_ptr<Dlt698Apdu> apdu, shared_ptr<Dlt698GetResponseNormalList> req)
{
    if(req->getResults().size() != 3)
        return;

    TerminalService *service = new TerminalService();
    TerminalEntity *entity = service->getOne(Dlt698Proctol::byteToString(apdu->getSA()->getAddrDat().data(), apdu->getSA()->getAddrDat().size()));

    delete service;

    if(entity == nullptr)
    {
        qDebug() << "addr 不存在";
        return;
    }

    TerminalInfoEntity *entityInfo = new TerminalInfoEntity();
    entityInfo->setTerminalId(entity->getId());

    shared_ptr<ResultNormal> result = req->getResults().at(0);
    entityInfo->setCurrent(result->getResult()->data);

    result = req->getResults().at(1);
    if(result->getResult()->data->getChildsSize() < 2)
    {
        qDebug() << result->getResult()->data->getChildsSize();
    }
    else
    {
        entityInfo->setLongitude(result->getResult()->data->getChild(0));
        entityInfo->setLatitude(result->getResult()->data->getChild(1));
    }

    result = req->getResults().at(2);
    entityInfo->setDateTime(result->getResult()->data);

    TerminalInfoService *serviceInfo = new TerminalInfoService();

    serviceInfo->save(*entityInfo);

    delete serviceInfo;
    delete entityInfo;
    delete entity;
}

void MyServiceReportNotificationList::doService(Dlt698::ServiceRequest &request, Dlt698::ServiceResponse &response)
{
    qDebug() << "ReportNotificationList: 88 01";

    MyServiceResponse *res = dynamic_cast<MyServiceResponse*>(&response);
    size_t pos;
    Dlt698ServerApdu server;
    pos = 0;
    server.decode(request.getApdu()->getByASDU(), pos);

    Dlt698ReportNotification report;
    pos = 0;
    report.decode(server.getBody(), pos);

    shared_ptr<Dlt698GetResponseNormalList> req(new Dlt698GetResponseNormalList());
    pos = 0;
    req->decode(report.getBody(), pos);

    this->currentPossitonTime(request.getApdu(), req);

    ReportResponseRecordListBuilder builder;

    for(auto &k : req->getResults())
    {
        builder.oad(k->getOad());
    }

    vector<BYTE> buff =
    builder.responseType(_mReportResponse::ReportResponseList)
            ->cliAddr(request.getApdu()->getByCA())
            ->srvAddr(request.getApdu()->getSA())
            ->build();

    res->getEvent()->getSocket().write(buff.data(), buff.size());
}

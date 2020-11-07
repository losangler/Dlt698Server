#include "myservicelinkrequest.h"
#include "myserviceresponse.h"
#include "dlt698linkrequest.h"
#include "dlt698linkapdu.h"
#include "linkresponsebuilder.h"
#include "terminalservice.h"
#include "terminalentity.h"
#include <QDebug>

using namespace Dlt698;

MyServiceLinkRequest::MyServiceLinkRequest()
{

}

void MyServiceLinkRequest::doService(Dlt698::ServiceRequest &request, Dlt698::ServiceResponse &response)
{
    shared_ptr<Dlt698DateTime> revTime(new Dlt698DateTime(true));
    qDebug() << "LinkRequest: 01";

    MyServiceResponse *res = dynamic_cast<MyServiceResponse*>(&response);
    size_t pos;
    Dlt698LinkApdu apdu;
    pos = 0;
    apdu.decode(request.getApdu()->getByASDU(), pos);

    Dlt698LinkRequest req;
    pos = 0;
    req.decode(apdu.getBody(), pos);

    TerminalEntity entity;
    entity.setAddr(apdu.byteToString(request.getApdu()->getSA()->getAddrDat().data(), request.getApdu()->getSA()->getAddrDat().size()));
    entity.setStatus(1);

    TerminalService service;
    if(service.getOne(entity.getAddr()) == nullptr)
        service.save(entity);

    shared_ptr<Dlt698DateTime> resTime(new Dlt698DateTime(true));

    LinkResponseBuilder builder;
    vector<BYTE> buff =
    builder.requestTime(req.getReqtime())
            ->receiveTime(revTime)
            ->responseTime(resTime)
            ->clock(1)
            ->cliAddr(request.getApdu()->getByCA())
            ->srvAddr(request.getApdu()->getSA())
            ->build();

    res->getEvent()->getSocket().write(buff.data(), buff.size());
}

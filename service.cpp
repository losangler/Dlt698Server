#include "service.h"

#include <QString>
#include <QDebug>

#include "dlt698oad.h"
#include "dlt698road.h"
#include "dlt698csd.h"
#include "dlt698data.h"
#include "dlt698datetime.h"
#include "dlt698reportnotification.h"
#include "dlt698apdu.h"
#include "dlt698getresponserecordlist.h"

#include "reportresponserecordlistbuilder.h"
#include "connectresponsebuilder.h"
#include "linkresponsebuilder.h"

using namespace Dlt698;

service::service()
{

}

vector<BYTE> service::doResponse()
{
    shared_ptr<Dlt698Apdu> apdu(new Dlt698Apdu());

    shared_ptr<Dlt698CtrlDomain> ctrl(new Dlt698CtrlDomain());
    ctrl->setPRM(1);
    ctrl->setDIR(1);
    ctrl->setFunc(3);

    shared_ptr<Dlt698SrvAddr> srvAddr(new Dlt698SrvAddr());
    vector<BYTE> addr(6,0);
    addr[0] = 1;
    srvAddr->setAddrDat(addr);
    apdu->setByCA(0x10);


    shared_ptr<ReportResponseRecordListBuilder> builder(new ReportResponseRecordListBuilder());

    shared_ptr<Dlt698Oad> oad(new Dlt698Oad());
    oad->setAttrId(2);
    oad->setOi(0x5004);

    return
    builder ->oad(oad)
            ->ctrl(ctrl)
            ->srvAddr(srvAddr)
            ->build();
}

vector<BYTE> service::doLinkResponse()
{
    shared_ptr<LinkResponseBuilder> builder(new LinkResponseBuilder());

    shared_ptr<Dlt698DateTime> time(new Dlt698DateTime());
    timeval tv;
    gettimeofday(&tv, nullptr);
    time->setDateTime(tv);

    return
    builder ->clock(1)
            ->requestTime(time)
            ->responseTime(time)
            ->responseTime(time)
            ->build();
}

vector<BYTE> service::doReportResponseRecordList()
{
    shared_ptr<ReportResponseRecordListBuilder> builder(new ReportResponseRecordListBuilder());

    shared_ptr<Dlt698Piid> piid(new Dlt698Piid());
    piid->setIdx(0);
    piid->setPri(1);
    piid->setRes(0);

    shared_ptr<Dlt698Oad> oad(new Dlt698Oad());
    oad->setAttrId(2);
    oad->setOi(0x5004);

    return
    builder ->oad(oad)
            ->piid(piid)
            ->build();
}

vector<BYTE> service::doConnectResponse()
{
    shared_ptr<ConnectResponseBuilder> builder(new ConnectResponseBuilder());
    return
    builder ->protVer(0x0010)
            ->cliSndFrameMaxSize(0x0400)
            ->cliRcvFrameMaxSize(0x0400)
            ->cliRcvFrameMaxWindow(0x01)
            ->cliApduMaxSize(0x0400)
            ->connectTimeOut(0x64)
            ->build();
}

vector<BYTE> service::doIndication(const vector<BYTE> &data)
{
    vector<BYTE> *res = new vector<BYTE>();


    return *res;
}

QString service::byteToString(const BYTE convert_data[], int convert_len)
{
    return QString::fromStdString(Dlt698Proctol::byteToString(convert_data, convert_len));
}

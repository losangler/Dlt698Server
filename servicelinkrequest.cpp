#include "servicelinkrequest.h"
#include "dlt698servicefactory.h"
#include "dlt698linkrequest.h"
#include "dlt698linkapdu.h"

#include <QDebug>

using namespace Dlt698;

ServiceLinkRequest::ServiceLinkRequest()
{
    WORD type = this->getServiceType(LinkRequest);
    Dlt698ServiceFactory::instance()->setService(type, this);
}

void ServiceLinkRequest::doService(ServiceRequest &request, ServiceResponse &response)
{
    qDebug() << "LinkRequest: 01";

    size_t pos;
    Dlt698LinkApdu apdu;
    pos = 0;
    apdu.decode(request.getApdu()->getByASDU(), pos);

    Dlt698LinkRequest req;
    pos = 0;
    req.decode(apdu.getBody(), pos);

    qDebug() << QString::fromStdString(req.toHexString());
}

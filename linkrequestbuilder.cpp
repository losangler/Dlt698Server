#include "linkrequestbuilder.h"

using namespace Dlt698;

LinkRequestBuilder::LinkRequestBuilder()
{
    this->linkRequest = shared_ptr<Dlt698LinkRequest>(new Dlt698LinkRequest());
    this->linkApdu->setSevType(LinkRequest);

    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu->getCtrl();
    ctrl->setDIR(1);
}

LinkRequestBuilder *LinkRequestBuilder::piid(const shared_ptr<Dlt698PiidAcd> &value)
{
    this->linkRequest->setPiid(value);
    return this;
}

LinkRequestBuilder *LinkRequestBuilder::linkRequestType(const _mLinkRequest::eReqTyp &value)
{
    this->linkRequest->setSevType(value);
    return this;
}

LinkRequestBuilder *LinkRequestBuilder::heartCycle(const long_unsigned_c &value)
{
    this->linkRequest->setHeartcycle(value);
    return this;
}

LinkRequestBuilder *LinkRequestBuilder::reqTime(const shared_ptr<Dlt698DateTime> &value)
{
    this->linkRequest->setReqtime(value);
    return this;
}

shared_ptr<Dlt698LinkRequest> LinkRequestBuilder::linkRequestBuild()
{
    return this->linkRequest;
}

vector<BYTE> LinkRequestBuilder::linkBodyBuild()
{
    return this->linkRequestBuild()->toBytes();
}

#include "linkresponsebuilder.h"

using namespace Dlt698;

LinkResponseBuilder::LinkResponseBuilder()
{
    this->linkResponse = shared_ptr<Dlt698LinkResponse>(new Dlt698LinkResponse());
    this->linkApdu->setSevType(LinkRespnose);

    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu->getCtrl();
    ctrl->setDIR(0);
}

LinkResponseBuilder *LinkResponseBuilder::piid(const shared_ptr<Dlt698Piid> &value)
{
    this->linkResponse->setPiid(value);
    return this;
}

LinkResponseBuilder *LinkResponseBuilder::requestTime(const shared_ptr<Dlt698DateTime> &value)
{
    this->linkResponse->setRequestTime(value);
    return this;
}

LinkResponseBuilder *LinkResponseBuilder::receiveTime(const shared_ptr<Dlt698DateTime> &value)
{
    this->linkResponse->setReceiveTime(value);
    return this;
}

LinkResponseBuilder *LinkResponseBuilder::responseTime(const shared_ptr<Dlt698DateTime> &value)
{
    this->linkResponse->setResponseTime(value);
    return this;
}

LinkResponseBuilder *LinkResponseBuilder::clock(const BYTE &value)
{
    this->linkResponse->setClock(value);
    return this;
}

LinkResponseBuilder *LinkResponseBuilder::result(const BYTE &value)
{
    this->linkResponse->setRslt(value);
    return this;
}

LinkResponseBuilder *LinkResponseBuilder::response(const BYTE &value)
{
    this->linkResponse->setRes(value);
    return this;
}

shared_ptr<Dlt698LinkResponse> LinkResponseBuilder::linkResponseBuild()
{
    return this->linkResponse;
}

vector<BYTE> LinkResponseBuilder::linkBodyBuild()
{
    return this->linkResponseBuild()->toBytes();
}

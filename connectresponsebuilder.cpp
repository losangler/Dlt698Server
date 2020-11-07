#include "connectresponsebuilder.h"

using namespace Dlt698;

ConnectResponseBuilder::ConnectResponseBuilder()
{
    this->response = shared_ptr<Dlt698ConnectResponse>(new Dlt698ConnectResponse());
    this->srvApdu->setSevType(ConnectResponse);

    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu->getCtrl();
    ctrl->setPRM(1);
}

ConnectResponseBuilder *ConnectResponseBuilder::piid(const shared_ptr<Dlt698Piid> &value)
{
    this->response->setPiid(value);
    return this;
}

ConnectResponseBuilder *ConnectResponseBuilder::factoryVer(const shared_ptr<_ConnectResponse::FactoryVersion> &value)
{
    this->response->setFactoryver(value);
    return this;
}

ConnectResponseBuilder *ConnectResponseBuilder::protVer(const long_unsigned_c &value)
{
    this->response->setProtver(value);
    return this;
}

ConnectResponseBuilder *ConnectResponseBuilder::protConf(const shared_ptr<Dlt698ProtocolConformance> &value)
{
    this->response->setProtconf(value);
    return this;
}

ConnectResponseBuilder *ConnectResponseBuilder::funConf(const shared_ptr<Dlt698FunctionConformance> &value)
{
    this->response->setFunconf(value);
    return this;
}

ConnectResponseBuilder *ConnectResponseBuilder::cliSndFrameMaxSize(const long_unsigned_c &value)
{
    this->response->setClisndframemaxsize(value);
    return this;
}

ConnectResponseBuilder *ConnectResponseBuilder::cliRcvFrameMaxSize(const long_unsigned_c &value)
{
    this->response->setClircvframemaxsize(value);
    return this;
}

ConnectResponseBuilder *ConnectResponseBuilder::cliRcvFrameMaxWindow(const unsigned_c &value)
{
    this->response->setClircvframemaxwindow(value);
    return this;
}

ConnectResponseBuilder *ConnectResponseBuilder::cliApduMaxSize(const long_unsigned_c &value)
{
    this->response->setCliapdumaxsize(value);
    return this;
}

ConnectResponseBuilder *ConnectResponseBuilder::connectTimeOut(const double_long_unsigned_c &value)
{
    this->response->setConnecttimeout(value);
    return this;
}

ConnectResponseBuilder *ConnectResponseBuilder::responseInfo(const shared_ptr<Dlt698ConnectResponseInfo> &value)
{
    this->response->setResponseInfo(value);
    return this;
}

shared_ptr<Dlt698ConnectResponse> ConnectResponseBuilder::responseBuild()
{
    return this->response;
}

vector<BYTE> ConnectResponseBuilder::serverBodyBuild()
{
    return this->responseBuild()->toBytes();
}

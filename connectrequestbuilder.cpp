#include "connectrequestbuilder.h"

using namespace Dlt698;

ConnectRequestBuilder::ConnectRequestBuilder()
{
    this->request = shared_ptr<Dlt698ConnectRequest>(new Dlt698ConnectRequest());
    this->cliApdu->setSevType(ConnectRequest);

    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu->getCtrl();
    ctrl->setPRM(1);
}

ConnectRequestBuilder *ConnectRequestBuilder::piid(const shared_ptr<Dlt698Piid> &value)
{
    this->request->setPiid(value);
    return this;
}

ConnectRequestBuilder *ConnectRequestBuilder::protVer(const long_unsigned_c &value)
{
    this->request->setProtver(value);
    return this;
}

ConnectRequestBuilder *ConnectRequestBuilder::protConf(const shared_ptr<Dlt698ProtocolConformance> &value)
{
    this->request->setProtconf(value);
    return this;
}

ConnectRequestBuilder *ConnectRequestBuilder::funConf(const shared_ptr<Dlt698FunctionConformance> &value)
{
    this->request->setFunconf(value);
    return this;
}

ConnectRequestBuilder *ConnectRequestBuilder::cliSndFrameMaxSize(const long_unsigned_c &value)
{
    this->request->setClisndframemaxsize(value);
    return this;
}

ConnectRequestBuilder *ConnectRequestBuilder::cliRcvFrameMaxSize(const long_unsigned_c &value)
{
    this->request->setClircvframemaxsize(value);
    return this;
}

ConnectRequestBuilder *ConnectRequestBuilder::cliRcvFrameMaxWindow(const unsigned_c &value)
{
    this->request->setClircvframemaxwindow(value);
    return this;
}

ConnectRequestBuilder *ConnectRequestBuilder::cliApduMaxSize(const long_unsigned_c &value)
{
    this->request->setCliapdumaxsize(value);
    return this;
}

ConnectRequestBuilder *ConnectRequestBuilder::connectTimeOut(const double_long_unsigned_c &value)
{
    this->request->setConnecttimeout(value);
    return this;
}

ConnectRequestBuilder *ConnectRequestBuilder::mechanismInfo(const shared_ptr<Dlt698ConnectMechanismInfo> &value)
{
    this->request->setMechanisminfo(value);
    return this;
}

shared_ptr<Dlt698ConnectRequest> ConnectRequestBuilder::requestBuild()
{
    return this->request;
}

vector<BYTE> ConnectRequestBuilder::clientBodyBuild()
{
    return this->requestBuild()->toBytes();
}

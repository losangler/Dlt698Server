#include "serverapdubuilder.h"

using namespace Dlt698;

ServerApduBuilder::ServerApduBuilder()
{
    this->srvApdu = shared_ptr<Dlt698ServerApdu>(new Dlt698ServerApdu());

    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu->getCtrl();
    ctrl->setDIR(1);
    ctrl->setFunc(3);
}

ServerApduBuilder *ServerApduBuilder::serverType(const eServerAPDU &value)
{
    this->srvApdu->setSevType(value);
    return this;
}

ServerApduBuilder *ServerApduBuilder::serverBody(const vector<BYTE> &value)
{
    this->srvApdu->setBody(value);
    return this;
}

ServerApduBuilder *ServerApduBuilder::followReportExist(const bool_c &value)
{
    this->srvApdu->setFollowReportExist(value);
    return this;
}

ServerApduBuilder *ServerApduBuilder::followReport(const shared_ptr<Dlt698FollowReport> &value)
{
    this->srvApdu->setFollowReport(value);
    return this;
}

ServerApduBuilder *ServerApduBuilder::timeTagExist(const bool_c &value)
{
    this->srvApdu->setTimeTagExist(value);
    return this;
}

ServerApduBuilder *ServerApduBuilder::timeTag(const shared_ptr<Dlt698TimeTag> &value)
{
    this->srvApdu->setTimeTag(value);
    return this;
}

shared_ptr<Dlt698ServerApdu> ServerApduBuilder::serverBuild()
{
    this->srvApdu->setBody(this->serverBodyBuild());
    return this->srvApdu;
}

vector<BYTE> ServerApduBuilder::asduBuild()
{
    return this->serverBuild()->toBytes();
}

vector<BYTE> ServerApduBuilder::serverBodyBuild()
{
    return this->srvApdu->getBody();
}

#include "clientapdubuilder.h"

using namespace Dlt698;

ClientApduBuilder::ClientApduBuilder()
{
    this->cliApdu = shared_ptr<Dlt698ClientApdu>(new Dlt698ClientApdu());

    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu->getCtrl();
    ctrl->setDIR(0);
    ctrl->setFunc(3);
}

ClientApduBuilder *ClientApduBuilder::clientBody(const vector<BYTE> &value)
{
    this->cliApdu->setBody(value);
    return this;
}

ClientApduBuilder *ClientApduBuilder::timeTagExist(const bool_c &value)
{
    this->cliApdu->setTimeTagExist(value);
    return this;
}

ClientApduBuilder *ClientApduBuilder::timeTag(const shared_ptr<Dlt698TimeTag> &value)
{
    this->cliApdu->setTimeTag(value);
    return this;
}

shared_ptr<Dlt698ClientApdu> ClientApduBuilder::clientBuild()
{
    this->cliApdu->setBody(this->clientBodyBuild());
    return this->cliApdu;
}

vector<BYTE> ClientApduBuilder::asduBuild()
{
    return this->clientBuild()->toBytes();
}

vector<BYTE> ClientApduBuilder::clientBodyBuild()
{
    return this->cliApdu->getBody();
}

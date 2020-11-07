#include "linkapdubuilder.h"

using namespace Dlt698;

LinkApduBuilder::LinkApduBuilder()
{
    this->linkApdu = shared_ptr<Dlt698LinkApdu>(new Dlt698LinkApdu());
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu->getCtrl();
    ctrl->setPRM(0);
    ctrl->setFunc(1);
}

LinkApduBuilder *LinkApduBuilder::linktype(const eLinkAPDU &value)
{
    this->linkApdu->setSevType(value);
    return this;
}

LinkApduBuilder *LinkApduBuilder::linkBody(const vector<BYTE> &value)
{
    this->linkApdu->setBody(value);
    return this;
}

shared_ptr<Dlt698LinkApdu> LinkApduBuilder::linkBuild()
{
    this->linkApdu->setBody(this->linkBodyBuild());
    return this->linkApdu;
}

vector<BYTE> LinkApduBuilder::asduBuild()
{
    return this->linkBuild()->toBytes();
}

vector<BYTE> LinkApduBuilder::linkBodyBuild()
{
    return this->linkApdu->getBody();
}

#include "apdubuilder.h"

using namespace Dlt698;

ApduBuilder::ApduBuilder()
{
    this->apdu = shared_ptr<Dlt698Apdu>(new Dlt698Apdu());
    this->apdu->getSA()->addAddrDat(0);
}

ApduBuilder *ApduBuilder::len(const shared_ptr<Dlt698LenDomain> &value)
{
    this->apdu->setLen(value);
    return this;
}

ApduBuilder *ApduBuilder::ctrl(const shared_ptr<Dlt698CtrlDomain> &value)
{
    this->apdu->setCtrl(value);
    return this;
}

ApduBuilder *ApduBuilder::srvAddr(const shared_ptr<Dlt698SrvAddr> &value)
{
    this->apdu->setSA(value);
    return this;
}

ApduBuilder *ApduBuilder::cliAddr(const BYTE &value)
{
    this->apdu->setByCA(value);
    return this;
}

shared_ptr<Dlt698Apdu> ApduBuilder::apduBuild()
{
    this->apdu->setByASDU(this->asduBuild());
    return this->apdu;
}

vector<BYTE> ApduBuilder::build()
{
    vector<BYTE> res;
    this->apduBuild()->encode(res);
    return res;
}

vector<BYTE> ApduBuilder::asduBuild()
{
    this->apdu->getByASDU();
}

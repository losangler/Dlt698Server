#ifndef APDUBUILDER_H
#define APDUBUILDER_H

#include "dlt698apdu.h"

namespace Dlt698 {

class ApduBuilder
{
public:
    ApduBuilder();

    ApduBuilder* len(const shared_ptr<Dlt698LenDomain> &value);

    ApduBuilder* ctrl(const shared_ptr<Dlt698CtrlDomain> &value);

    ApduBuilder* srvAddr(const shared_ptr<Dlt698SrvAddr> &value);

    ApduBuilder* cliAddr(const BYTE &value);

    ApduBuilder* ASDU(const vector<BYTE> &value);

    shared_ptr<Dlt698Apdu> apduBuild();

    vector<BYTE> build();
protected:
    virtual vector<BYTE> asduBuild();

    shared_ptr<Dlt698Apdu> apdu;
};

}

#endif // APDUBUILDER_H

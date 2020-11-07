#ifndef CLIENTAPDUBUILDER_H
#define CLIENTAPDUBUILDER_H

#include "apdubuilder.h"
#include "dlt698clientapdu.h"

namespace Dlt698 {

class ClientApduBuilder : public ApduBuilder
{
public:
    ClientApduBuilder();

    ClientApduBuilder* clientSevType(const eClientAPDU &value);

    ClientApduBuilder* clientBody(const vector<BYTE> &value);

    ClientApduBuilder* timeTagExist(const bool_c &value);

    ClientApduBuilder* timeTag(const shared_ptr<Dlt698TimeTag> &value);

    shared_ptr<Dlt698ClientApdu> clientBuild();
    // ApduBuilder interface
protected:
    vector<BYTE> asduBuild() override final;

    virtual vector<BYTE> clientBodyBuild();

    shared_ptr<Dlt698ClientApdu> cliApdu;
};

}

#endif // CLIENTAPDUBUILDER_H

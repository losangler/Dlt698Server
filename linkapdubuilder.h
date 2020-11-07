#ifndef LINKAPDUBUILDER_H
#define LINKAPDUBUILDER_H

#include "apdubuilder.h"
#include "dlt698linkapdu.h"

namespace Dlt698 {

class LinkApduBuilder : public ApduBuilder
{
public:
    LinkApduBuilder();

    LinkApduBuilder* linktype(const eLinkAPDU &value);

    LinkApduBuilder* linkBody(const vector<BYTE> &value);

    shared_ptr<Dlt698LinkApdu> linkBuild();

    // ApduBuilder interface
protected:
    vector<BYTE> asduBuild() override final;

    virtual vector<BYTE> linkBodyBuild();

    shared_ptr<Dlt698LinkApdu> linkApdu;
};

}

#endif // LINKAPDUBUILDER_H

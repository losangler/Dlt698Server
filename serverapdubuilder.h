#ifndef SERVERAPDUBUILDER_H
#define SERVERAPDUBUILDER_H

#include "apdubuilder.h"
#include "dlt698serverapdu.h"

namespace Dlt698 {

class ServerApduBuilder : public ApduBuilder
{
public:
    ServerApduBuilder();

    ServerApduBuilder* serverType(const eServerAPDU &value);

    ServerApduBuilder* serverBody(const vector<BYTE> &value);

    ServerApduBuilder* followReportExist(const bool_c &value);

    ServerApduBuilder* followReport(const shared_ptr<Dlt698FollowReport> &value);

    ServerApduBuilder* timeTagExist(const bool_c &value);

    ServerApduBuilder* timeTag(const shared_ptr<Dlt698TimeTag> &value);

    shared_ptr<Dlt698ServerApdu> serverBuild();

    // ApduBuilder interface
protected:
    vector<BYTE> asduBuild() override final;

    virtual vector<BYTE> serverBodyBuild();

    shared_ptr<Dlt698ServerApdu> srvApdu;
};

}


#endif // SERVERAPDUBUILDER_H

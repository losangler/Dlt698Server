#ifndef CONNECTRESPONSEBUILDER_H
#define CONNECTRESPONSEBUILDER_H

#include "serverapdubuilder.h"
#include "dlt698connectresponse.h"

namespace Dlt698 {

class ConnectResponseBuilder : public ServerApduBuilder
{
public:
    ConnectResponseBuilder();

    ConnectResponseBuilder* piid(const shared_ptr<Dlt698Piid> &value);

    ConnectResponseBuilder* factoryVer(const shared_ptr<_ConnectResponse::FactoryVersion> &value);

    ConnectResponseBuilder* protVer(const long_unsigned_c &value);

    ConnectResponseBuilder* protConf(const shared_ptr<Dlt698ProtocolConformance> &value);

    ConnectResponseBuilder* funConf(const shared_ptr<Dlt698FunctionConformance> &value);

    ConnectResponseBuilder* cliSndFrameMaxSize(const long_unsigned_c &value);

    ConnectResponseBuilder* cliRcvFrameMaxSize(const long_unsigned_c &value);

    ConnectResponseBuilder* cliRcvFrameMaxWindow(const unsigned_c &value);

    ConnectResponseBuilder* cliApduMaxSize(const long_unsigned_c &value);

    ConnectResponseBuilder* connectTimeOut(const double_long_unsigned_c &value);

    ConnectResponseBuilder* responseInfo(const shared_ptr<Dlt698ConnectResponseInfo> &value);

    shared_ptr<Dlt698ConnectResponse> responseBuild();

    // ServerApduBuilder interface
protected:
    vector<BYTE> serverBodyBuild() override final;

    shared_ptr<Dlt698ConnectResponse> response;
};

}

#endif // CONNECTRESPONSEBUILDER_H

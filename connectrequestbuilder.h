#ifndef CONNECTREQUESTBUILDER_H
#define CONNECTREQUESTBUILDER_H

#include "clientapdubuilder.h"
#include "dlt698connectrequest.h"

namespace Dlt698 {

class ConnectRequestBuilder : public ClientApduBuilder
{
public:
    ConnectRequestBuilder();

    ConnectRequestBuilder* piid(const shared_ptr<Dlt698Piid> &value);

    ConnectRequestBuilder* protVer(const long_unsigned_c &value);

    ConnectRequestBuilder* protConf(const shared_ptr<Dlt698ProtocolConformance> &value);

    ConnectRequestBuilder* funConf(const shared_ptr<Dlt698FunctionConformance> &value);

    ConnectRequestBuilder* cliSndFrameMaxSize(const long_unsigned_c &value);

    ConnectRequestBuilder* cliRcvFrameMaxSize(const long_unsigned_c &value);

    ConnectRequestBuilder* cliRcvFrameMaxWindow(const unsigned_c &value);

    ConnectRequestBuilder* cliApduMaxSize(const long_unsigned_c &value);

    ConnectRequestBuilder* connectTimeOut(const double_long_unsigned_c &value);

    ConnectRequestBuilder* mechanismInfo(const shared_ptr<Dlt698ConnectMechanismInfo> &value);

    shared_ptr<Dlt698ConnectRequest> requestBuild();

    // ClientApduBuilder interface
protected:
    vector<BYTE> clientBodyBuild() override final;

    shared_ptr<Dlt698ConnectRequest> request;
};

}

#endif // CONNECTREQUESTBUILDER_H

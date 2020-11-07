#ifndef LINKRESPONSEBUILDER_H
#define LINKRESPONSEBUILDER_H

#include "linkapdubuilder.h"
#include "dlt698linkresponse.h"

namespace Dlt698{

class LinkResponseBuilder : public LinkApduBuilder
{
public:
    LinkResponseBuilder();

    LinkResponseBuilder* piid(const shared_ptr<Dlt698Piid> &value);

    LinkResponseBuilder* requestTime(const shared_ptr<Dlt698DateTime> &value);

    LinkResponseBuilder* receiveTime(const shared_ptr<Dlt698DateTime> &value);

    LinkResponseBuilder* responseTime(const shared_ptr<Dlt698DateTime> &value);

    LinkResponseBuilder* clock(const BYTE &value);

    LinkResponseBuilder* result(const BYTE &value);

    LinkResponseBuilder* response(const BYTE &value);

    shared_ptr<Dlt698LinkResponse> linkResponseBuild();

    // LinkApduBuilder interface
protected:
    vector<BYTE> linkBodyBuild() override final;

    shared_ptr<Dlt698LinkResponse> linkResponse;
};

}

#endif // LINKRESPONSEBUILDER_H

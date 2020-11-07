#ifndef LINKREQUESTBUILDER_H
#define LINKREQUESTBUILDER_H

#include "linkapdubuilder.h"
#include "dlt698linkrequest.h"

namespace Dlt698 {

class LinkRequestBuilder : public LinkApduBuilder
{
public:
    LinkRequestBuilder();

    LinkRequestBuilder* piid(const shared_ptr<Dlt698PiidAcd> &value);

    LinkRequestBuilder* linkRequestType(const _mLinkRequest::eReqTyp &value);

    LinkRequestBuilder* heartCycle(const long_unsigned_c &value);

    LinkRequestBuilder* reqTime(const shared_ptr<Dlt698DateTime> &value);

    shared_ptr<Dlt698LinkRequest> linkRequestBuild();

    // LinkApduBuilder interface
protected:
    vector<BYTE> linkBodyBuild() override final;

    shared_ptr<Dlt698LinkRequest> linkRequest;
};

}

#endif // LINKREQUESTBUILDER_H

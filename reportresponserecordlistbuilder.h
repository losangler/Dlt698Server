#ifndef REPORTRESPONSERECORDLISTBUILDER_H
#define REPORTRESPONSERECORDLISTBUILDER_H

#include "reportresponsebuilder.h"
#include "dlt698reportresponserecordlist.h"

namespace Dlt698 {

class ReportResponseRecordListBuilder : public ReportResponseBuilder
{
public:
    ReportResponseRecordListBuilder();

    ReportResponseRecordListBuilder* piid(const shared_ptr<Dlt698Piid> &value);

    ReportResponseRecordListBuilder* oads(const vector<shared_ptr<Dlt698Oad> > &value);

    ReportResponseRecordListBuilder* oad(const shared_ptr<Dlt698Oad> &value);

    shared_ptr<Dlt698ReportResponseRecordList> responseRecordBuild();
    // ReportResponseBuilder interface
protected:
    vector<BYTE> responseBodyBuild() override final;

    shared_ptr<Dlt698ReportResponseRecordList> responseRecord;
};

}

#endif // REPORTRESPONSERECORDLISTBUILDER_H

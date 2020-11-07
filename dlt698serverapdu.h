#ifndef DLT698SERVERAPDU_H
#define DLT698SERVERAPDU_H

#include "dlt698timetag.h"
#include "dlt698followreport.h"

class Dlt698ServerApdu : public Dlt698Proctol
{
public:
    Dlt698ServerApdu(eServerAPDU type = ReportNotification);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    eServerAPDU getSevType() const;
    void setSevType(const eServerAPDU &value);

    vector<BYTE> getBody() const;
    void setBody(const vector<BYTE> &value);

    bool_c getFollowReportExist() const;
    void setFollowReportExist(const bool_c &value);

    shared_ptr<Dlt698FollowReport> getFollowReport() const;
    void setFollowReport(const shared_ptr<Dlt698FollowReport> &value);

    bool_c getTimeTagExist() const;
    void setTimeTagExist(const bool_c &value);

    shared_ptr<Dlt698TimeTag> getTimeTag() const;
    void setTimeTag(const shared_ptr<Dlt698TimeTag> &value);

private:
    eServerAPDU sevType;

    vector<BYTE> body;

    bool_c followReportExist;

    shared_ptr<Dlt698FollowReport> followReport;

    bool_c timeTagExist;

    shared_ptr<Dlt698TimeTag> timeTag;
};

#endif // DLT698SERVERAPDU_H

#ifndef DLT698REPORTNOTIFICATION_H
#define DLT698REPORTNOTIFICATION_H

#include "dlt698proctol.h"

namespace _mReportNotification {

typedef enum _eREPORTNotification
{
    ReportNotificationList=1,//上报若干个对象属性         [1] ，
    ReportNotificationRecordList,//上报若干个记录型对象属性   [2] ，
    ReportNotificationTransData//上报透明数据               [3]

}eReportNotification;

}

class Dlt698ReportNotification : public Dlt698Proctol
{
public:
    Dlt698ReportNotification(_mReportNotification::eReportNotification type = _mReportNotification::ReportNotificationRecordList);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    _mReportNotification::eReportNotification getSevType() const;
    void setSevType(const _mReportNotification::eReportNotification &value);

    vector<BYTE> getBody() const;
    void setBody(const vector<BYTE> &value);

private:
    _mReportNotification::eReportNotification sevType;

    vector<BYTE> body;
};

#endif // DLT698REPORTNOTIFICATION_H

#ifndef SERVICE_H
#define SERVICE_H

#include "dlt698apdu.h"
#include "dlt698linkapdu.h"
#include "dlt698linkresponse.h"
#include "dlt698clientapdu.h"
#include "dlt698reportresponse.h"
#include "dlt698connectresponse.h"
#include "dlt698serverapdu.h"
#include "dlt698reportresponserecordlist.h"

class service
{
public:
    service();

    vector<BYTE> doResponse();

    vector<BYTE> doLinkResponse();

    vector<BYTE> doReportResponseRecordList();

    vector<BYTE> doConnectResponse();

    vector<BYTE> doIndication(const vector<BYTE> &data);

    QString byteToString(const BYTE convert_data[], int convert_len);
};

#endif // SERVICE_H

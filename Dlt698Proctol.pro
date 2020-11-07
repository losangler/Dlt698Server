#-------------------------------------------------
#
# Project created by QtCreator 2020-09-19T10:10:32
#
#-------------------------------------------------

QT       -= gui

TARGET = Dlt698Proctol
TEMPLATE = lib

DEFINES += DLT698PROCTOL_LIBRARY

SOURCES += dlt698proctol.cpp \
    dlt698oad.cpp \
    dlt698road.cpp \
    dlt698csd.cpp \
    dlt698rcsd.cpp \
    dlt698piidacd.cpp \
    dlt698datetime.cpp \
    dlt698data.cpp \
    dlt698resultrecord.cpp \
    dlt698getresponserecordlist.cpp \
    dlt698apdu.cpp \
    dlt698srvaddr.cpp \
    dlt698ctrldomain.cpp \
    dlt698lendomain.cpp \
    dlt698clientapdu.cpp \
    dlt698datetimes.cpp \
    dlt698ti.cpp \
    dlt698timetag.cpp \
    dlt698followreport.cpp \
    dlt698serverapdu.cpp \
    dlt698reportnotification.cpp \
    dlt698getresponserecord.cpp \
    dltstringbuffer.cpp \
    dltobject.cpp \
    dlt698linkapdu.cpp \
    dlt698linkrequest.cpp \
    dlt698piid.cpp \
    dlt698protocolconformance.cpp \
    dlt698functionconformance.cpp \
    dlt698connectrequest.cpp \
    dlt698connectmechanisminfo.cpp \
    dlt698linkresponse.cpp \
    dlt698reportresponse.cpp \
    dlt698reportresponserecordlist.cpp \
    dlt698connectresponse.cpp \
    dlt698connectresponseinfo.cpp \
    dlt698randnum.cpp \
    dlt698getresponsenormal.cpp \
    dlt698getresponsenormallist.cpp

HEADERS += dlt698proctol.h\
        dlt698proctol_global.h \
    dlt698datatypes.h \
    dlt698oad.h \
    dlt698road.h \
    dlt698csd.h \
    dlt698rcsd.h \
    dlt698piidacd.h \
    dlt698datetime.h \
    dlt698data.h \
    dlt698resultrecord.h \
    dlt698getresponserecordlist.h \
    dlt698apdu.h \
    dlt698srvaddr.h \
    dlt698ctrldomain.h \
    dlt698lendomain.h \
    dlt698clientapdu.h \
    dlt698datetimes.h \
    dlt698ti.h \
    dlt698timetag.h \
    dlt698followreport.h \
    dlt698serverapdu.h \
    dlt698reportnotification.h \
    dlt698getresponserecord.h \
    dltstringbuffer.h \
    dltobject.h \
    dlt698linkapdu.h \
    dlt698linkrequest.h \
    dlt698piid.h \
    dlt698protocolconformance.h \
    dlt698functionconformance.h \
    dlt698connectrequest.h \
    dlt698connectmechanisminfo.h \
    dlt698linkresponse.h \
    dlt698reportresponse.h \
    dlt698reportresponserecordlist.h \
    dlt698connectresponse.h \
    dlt698connectresponseinfo.h \
    dlt698randnum.h \
    dlt698getresponsenormal.h \
    dlt698getresponsenormallist.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

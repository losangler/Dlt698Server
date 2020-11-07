#-------------------------------------------------
#
# Project created by QtCreator 2020-09-22T14:47:00
#
#-------------------------------------------------

QT       -= gui

TARGET = Dlt698Service
TEMPLATE = lib

DEFINES += DLT698SERVICE_LIBRARY

SOURCES += dlt698service.cpp \
    dlt698servicefactory.cpp \
    servicereportnotificationrecordlist.cpp \
    dlt698callservice.cpp \
    apdubuilder.cpp \
    clientapdubuilder.cpp \
    reportresponsebuilder.cpp \
    reportresponserecordlistbuilder.cpp \
    connectrequestbuilder.cpp \
    serverapdubuilder.cpp \
    connectresponsebuilder.cpp \
    reportnotificationbuilder.cpp \
    reportnotificationrecordlistbuilder.cpp \
    linkapdubuilder.cpp \
    linkrequestbuilder.cpp \
    linkresponsebuilder.cpp \
    servicerequest.cpp \
    serviceresponse.cpp \
    servicelinkrequest.cpp \
    servicereportnotificationnormallist.cpp

HEADERS += dlt698service.h\
        dlt698service_global.h \
    dlt698servicefactory.h \
    servicereportnotificationrecordlist.h \
    dlt698callservice.h \
    apdubuilder.h \
    clientapdubuilder.h \
    reportresponsebuilder.h \
    reportresponserecordlistbuilder.h \
    connectrequestbuilder.h \
    serverapdubuilder.h \
    connectresponsebuilder.h \
    reportnotificationbuilder.h \
    reportnotificationrecordlistbuilder.h \
    linkapdubuilder.h \
    linkrequestbuilder.h \
    linkresponsebuilder.h \
    servicerequest.h \
    serviceresponse.h \
    servicelinkrequest.h \
    servicereportnotificationnormallist.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/release/ -lDlt698Proctol
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/debug/ -lDlt698Proctol
else:unix: LIBS += -L$$PWD/../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/ -lDlt698Proctol

INCLUDEPATH += $$PWD/../Dlt698Proctol
DEPENDPATH += $$PWD/../Dlt698Proctol

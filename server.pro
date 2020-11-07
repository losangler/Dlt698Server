#-------------------------------------------------
#
# Project created by QtCreator 2020-09-10T20:23:02
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    service.cpp \
    myclienthandler.cpp \
    threadforepoll.cpp \
    myservicelinkrequest.cpp \
    myserviceresponse.cpp \
    myservicereportnotificationlist.cpp \
    readtask.cpp

HEADERS  += widget.h \
    service.h \
    myclienthandler.h \
    threadforepoll.h \
    myservicelinkrequest.h \
    myserviceresponse.h \
    myservicereportnotificationlist.h \
    readtask.h

FORMS    += widget.ui client.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/release/ -lDlt698Proctol
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/debug/ -lDlt698Proctol
else:unix: LIBS += -L$$PWD/../../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/ -lDlt698Proctol

INCLUDEPATH += $$PWD/../../Dlt698Proctol
DEPENDPATH += $$PWD/../../Dlt698Proctol

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-Dlt698Service-Desktop_Qt_5_6_3_GCC_64bit-Debug/release/ -lDlt698Service
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-Dlt698Service-Desktop_Qt_5_6_3_GCC_64bit-Debug/debug/ -lDlt698Service
else:unix: LIBS += -L$$PWD/../../build-Dlt698Service-Desktop_Qt_5_6_3_GCC_64bit-Debug/ -lDlt698Service

INCLUDEPATH += $$PWD/../../Dlt698Service
DEPENDPATH += $$PWD/../../Dlt698Service

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-Epoller-Desktop_Qt_5_6_3_GCC_64bit-Debug/release/ -lEpoller
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-Epoller-Desktop_Qt_5_6_3_GCC_64bit-Debug/debug/ -lEpoller
else:unix: LIBS += -L$$PWD/../build-Epoller-Desktop_Qt_5_6_3_GCC_64bit-Debug/ -lEpoller

INCLUDEPATH += $$PWD/../Epoller
DEPENDPATH += $$PWD/../Epoller

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../build-Dlt698Mysql-Desktop_Qt_5_6_3_GCC_64bit-Debug/release/ -lDlt698Mysql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../build-Dlt698Mysql-Desktop_Qt_5_6_3_GCC_64bit-Debug/debug/ -lDlt698Mysql
else:unix: LIBS += -L$$PWD/../../build-Dlt698Mysql-Desktop_Qt_5_6_3_GCC_64bit-Debug/ -lDlt698Mysql

INCLUDEPATH += $$PWD/../../Dlt698Mysql
DEPENDPATH += $$PWD/../../Dlt698Mysql

#-------------------------------------------------
#
# Project created by QtCreator 2020-10-29T15:16:35
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = Dlt698Mysql
TEMPLATE = lib

DEFINES += DLT698MYSQL_LIBRARY

SOURCES += dlt698mysql.cpp \
    terminalentity.cpp \
    terminalservice.cpp \
    connectionpool.cpp \
    terminalinfoentity.cpp \
    terminalinfoservice.cpp \
    databaseservice.cpp

HEADERS += dlt698mysql.h\
        dlt698mysql_global.h \
    terminalentity.h \
    terminalservice.h \
    connectionpool.h \
    terminalinfoentity.h \
    terminalinfoservice.h \
    databaseservice.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/release/ -lDlt698Proctol
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/debug/ -lDlt698Proctol
else:unix: LIBS += -L$$PWD/../build-Dlt698Proctol-Desktop_Qt_5_6_3_GCC_64bit-Debug/ -lDlt698Proctol

INCLUDEPATH += $$PWD/../Dlt698Proctol
DEPENDPATH += $$PWD/../Dlt698Proctol

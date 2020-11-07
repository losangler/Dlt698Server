#-------------------------------------------------
#
# Project created by QtCreator 2020-10-10T09:31:18
#
#-------------------------------------------------

QT       -= gui

TARGET = Epoller
TEMPLATE = lib

DEFINES += EPOLLER_LIBRARY

SOURCES += epoller.cpp \
    handler.cpp \
    ioloop.cpp \
    serverhandler.cpp \
    tcpsocket.cpp \
    clienthandler.cpp \
    epollevent.cpp \
    thread.cpp \
    threadpool.cpp \
    task.cpp

HEADERS += epoller.h\
        epoller_global.h \
    handler.h \
    ioloop.h \
    serverhandler.h \
    tcpsocket.h \
    clienthandler.h \
    epollevent.h \
    thread.h \
    threadpool.h \
    task.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

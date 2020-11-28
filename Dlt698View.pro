TEMPLATE = app

QT += qml quick xml sql
CONFIG += c++11

SOURCES += main.cpp \
    dataobject.cpp \
    animalmodel.cpp \
    treeitem.cpp \
    treemodel.cpp \
    model/model.cpp \
    controller/controller.cpp \
    controller/connectcontroller.cpp \
    config/ConfigXml.cpp \
    config/configelement.cpp \
    model/servermodel.cpp \
    service/service.cpp \
    service/serverservice.cpp \
    service/connectionservice.cpp \
    dao/serverxmldao.cpp \
    model/terminalmodel.cpp \
    config/databasexml.cpp \
    dao/terminaldao.cpp \
    util/connectionpool.cpp \
    config/domxml.cpp \
    service/terminalservice.cpp \
    util/dbmanager.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    dataobject.h \
    animalmodel.h \
    treeitem.h \
    treemodel.h \
    model/model.h \
    controller/controller.h \
    controller/connectcontroller.h \
    config/ConfigXml.h \
    config/configelement.h \
    model/servermodel.h \
    service/service.h \
    service/serverservice.h \
    service/connectionservice.h \
    dao/xmldao.h \
    model/terminalmodel.h \
    config/databasexml.h \
    dao/serverxmldao.h \
    dao/databasedao.h \
    dao/terminaldao.h \
    util/connectionpool.h \
    config/domxml.h \
    service/terminalservice.h \
    util/dbmanager.h

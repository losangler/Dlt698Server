TEMPLATE = app

QT += qml quick xml
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
    config/configelement.cpp

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
    config/configelement.h

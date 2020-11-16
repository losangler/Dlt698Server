#include <QGuiApplication>
#include <QStringList>
#include <QQmlApplicationEngine>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include "controller/connectcontroller.h"
#include "config/ConfigXml.h"

const char* uri = "MyInterface";
const int versionMajor = 1;
const int versionMinor = 2;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Model>("MyInterface", versionMajor, versionMinor, "Model");
    qmlRegisterSingletonType<ConnectController>(uri, versionMajor, versionMinor, "ConnectController", ConnectController::singletontype_provider);

    ::qputenv("QT_QUICK_CONTROLS_CONF", "/home/arm/Dlt698View/config/qtquickcontrols.conf");

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}

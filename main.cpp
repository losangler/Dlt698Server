#include <QApplication>
#include <QStringList>
#include <QQmlApplicationEngine>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include "controller/connectcontroller.h"
#include "config/ConfigXml.h"
#include "util/connectionpool.h"

const char* uri = "MyInterface";
const int versionMajor = 1;
const int versionMinor = 8;

int main(int argc, char *argv[])
{
    Dlt698::ConnectionPool::getInstance().createConnection();
    Dlt698::ConnectionPool::getInstance().init();

    ::qputenv("QT_QUICK_CONTROLS_CONF", "../Dlt698View/config/qtquickcontrols.conf");

    QApplication app(argc, argv);

    qmlRegisterType<ServerModel>("MyInterface", versionMajor, versionMinor, "ServerModel");
    qmlRegisterType<QSqlQueryModel>(uri, versionMajor, versionMinor, "QSqlQueryModel");
    qmlRegisterSingletonType<ConnectController>(uri, versionMajor, versionMinor, "ConnectController", ConnectController::singletontype_provider);

    QQmlApplicationEngine engine;

    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}

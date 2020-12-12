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
#include "config/log.h"

const char* uri = "MyInterface";
const int versionMajor = 1;
const int versionMinor = 9;

int main(int argc, char *argv[])
{
    //日志初始化
    QT_LOG::logInit();

    //数据库初始化
    Dlt698::ConnectionPool::getInstance().createConnection();
    Dlt698::ConnectionPool::getInstance().init();

    //配置文件路径的环境变量
    ::qputenv("QT_QUICK_CONTROLS_CONF", "../Dlt698View/config/qtquickcontrols.conf");

    //c++接口注册
    QApplication app(argc, argv);
    qmlRegisterType<ServerModel>("MyInterface", versionMajor, versionMinor, "ServerModel");
    qmlRegisterType<QSqlQueryModel>(uri, versionMajor, versionMinor, "QSqlQueryModel");
    qmlRegisterSingletonType<ConnectController>(uri, versionMajor, versionMinor, "ConnectController", ConnectController::singletontype_provider);

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}

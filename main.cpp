#include <QGuiApplication>
#include <QStringList>
#include <QQmlApplicationEngine>

#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include "dataobject.h"
#include "animalmodel.h"
#include "treemodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    AnimalModel model;
    model.addAnimal(Animal("Wolf", "Medium"));
    model.addAnimal(Animal("Polar bear", "Large"));
    model.addAnimal(Animal("Quoll", "Small"));

    TreeModel treeModel;
//    QQuickView view;
//    view.setResizeMode(QQuickView::SizeRootObjectToView);

//    QQmlContext *ctxt = view.rootContext();
//    ctxt->setContextProperty("myModel", &model);

//    view.setSource(QUrl("qrc:/view.qml"));
//    view.show();

    ::qputenv("QT_QUICK_CONTROLS_CONF", "/home/arm/Dlt698View/config/qtquickcontrols.conf");

    engine.rootContext()->setContextProperty("myModel", &model);
    engine.rootContext()->setContextProperty("myTree", &treeModel);
    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}

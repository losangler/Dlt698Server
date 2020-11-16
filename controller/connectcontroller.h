#ifndef CONNECTCONTROLLER_H
#define CONNECTCONTROLLER_H

#include <QObject>
#include <QQmlEngine>
#include "model/model.h"
#include "controller/controller.h"

class ConnectController : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE void updateModel(const QString &name) const;

    Q_INVOKABLE Model *model();

    static QObject *singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    explicit ConnectController(QObject *parent = nullptr);

private:
    Model *m_model = nullptr;

    QString c_connect = "connect";
    QString c_port = "port";
};

#endif // CONNECTCONTROLLER_H

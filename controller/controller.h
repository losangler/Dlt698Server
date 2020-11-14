#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QQmlEngine>
#include "model/model.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);

    Q_INVOKABLE Model* getModel() const;
};

static QObject *singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Controller *example = new Controller;
    return example;
}

#endif

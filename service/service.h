#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include "model/model.h"
#include "config/configelement.h"

class Service : public QObject
{
    Q_OBJECT
public:
    explicit Service(QObject *parent = nullptr);

};

#endif // SERVICE_H

#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H

#include "service/service.h"

class ConnectionService : public Service
{
    Q_OBJECT
public:
    explicit ConnectionService(QObject* parent = nullptr);

    virtual Model *model() const;

    virtual void updateModel();
};

#endif // CONNECTIONSERVICE_H

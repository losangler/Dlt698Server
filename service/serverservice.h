#ifndef SERVERSERVICE_H
#define SERVERSERVICE_H

#include "config/configelement.h"
#include "service/connectionservice.h"
#include "model/servermodel.h"

class ServerService : public ConnectionService
{
public:
    explicit ServerService(QObject *parent);

private:
    const QString c_server = "server";
};

#endif // SERVERSERVICE_H

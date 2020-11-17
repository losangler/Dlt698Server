#ifndef SERVERSERVICE_H
#define SERVERSERVICE_H

#include "config/configelement.h"
#include "service.h"
#include "model/servermodel.h"

class ServerService : public Service
{
public:
    explicit ServerService(QObject *parent);

    ServerModel *serverModel() const;
    void setServerModel(ServerModel *serverModel);

    void updateServer();

private:
    ServerModel *m_serverModel = nullptr;
    ConfigElement m_elem;

    const QString c_connection = "connection";
    const QString c_server = "server";
    const QString c_ip = "ip";
    const QString c_port = "port";
    const QString c_timeout = "timeout";
    const QString c_connectmax = "connectmax";
};

#endif // SERVERSERVICE_H

#include "connectionservice.h"

ConnectionService::ConnectionService(QObject *parent)
    : Service(parent)
{

}

Model *ConnectionService::model() const
{
    return nullptr;
}

void ConnectionService::updateModel()
{

}

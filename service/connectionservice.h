#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H

#include "service/service.h"

class ConnectionService : public Service
{
    Q_OBJECT
public:
    explicit ConnectionService(QObject* parent = nullptr);

    Model *model() const;
    void setModel(Model *model);

    void initModel();
    void updateModel();

protected:
    ConfigElement m_elem;

    Model *m_model = nullptr;

    const QString c_connection = "connection";
};

#endif // CONNECTIONSERVICE_H

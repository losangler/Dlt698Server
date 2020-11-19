#ifndef SERVERSERVICE_H
#define SERVERSERVICE_H

#include "config/configelement.h"
#include "service/connectionservice.h"
#include "model/servermodel.h"
#include "dao/serverxmldao.h"
#include "dao/terminaldao.h"

class ServerService : public ConnectionService
{
public:
    explicit ServerService(QObject *parent);

    // ConnectionService interface
public:
    virtual Model *model() const override;
    virtual void updateModel() override;

private:
    ServerModel* m_model;

    ServerXmlDao m_dao;

    TerminalDao m_terminalDao;
};

#endif // SERVERSERVICE_H

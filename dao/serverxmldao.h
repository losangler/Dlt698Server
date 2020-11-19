#ifndef SERVERXMLDAO_H
#define SERVERXMLDAO_H

#include "xmldao.h"
#include "model/servermodel.h"

class ServerXmlDao : public XmlDao<ServerModel>
{
public:
    explicit ServerXmlDao(QObject* parent = nullptr);
};

#endif // SERVERXMLDAO_H

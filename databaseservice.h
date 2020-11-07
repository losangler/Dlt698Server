#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H

#include <QSqlDatabase>

namespace Dlt698 {

class DataBaseService
{
public:
    DataBaseService();

    virtual ~DataBaseService();

    bool queryExec(QSqlQuery &query, QString error);

protected:
    QSqlDatabase db;
};

}

#endif // DATABASESERVICE_H

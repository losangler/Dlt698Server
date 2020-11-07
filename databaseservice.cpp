#include "databaseservice.h"
#include "connectionpool.h"
#include <QDebug>

using namespace Dlt698;

DataBaseService::DataBaseService()
{
    db = ConnectionPool::getInstance().openConnection();
}

DataBaseService::~DataBaseService()
{
    ConnectionPool::getInstance().closeConnection(db);
}

bool DataBaseService::queryExec(QSqlQuery &query, QString error)
{
    if(!query.exec())
    {
        if(!this->db.open())
        {
            qDebug() << "reopen failed" << this->db.lastError();
            return false;
        }
        query = *(new QSqlQuery(this->db));
        if(!query.exec())
        {
            qDebug() << error << this->db.lastError();
            return false;
        }
    }
    return true;
}

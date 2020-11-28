#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "connectionpool.h"

class DbManager
{
public:
    DbManager(const QString& error = "error");

    ~DbManager();

    QSqlDatabase& db();

    void setDb(const QSqlDatabase &db);

    QSqlQuery& query();
    void setQuery(const QSqlQuery &query);

    QString& error();
    void setError(const QString &error);

private:
    QSqlDatabase m_db;

    QSqlQuery m_query;

    QString m_error;
};

#endif // DBMANAGER_H

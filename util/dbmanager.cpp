#include "dbmanager.h"

DbManager::DbManager(const QString &error)
    :m_error(error)
{
    m_db = Dlt698::ConnectionPool::getInstance().openConnection();
    m_query = QSqlQuery(m_db);
}

DbManager::~DbManager()
{
    Dlt698::ConnectionPool::getInstance().closeConnection(m_db);
}

QSqlDatabase &DbManager::db()
{
    return m_db;
}

void DbManager::setDb(const QSqlDatabase &db)
{
    m_db = db;
}

QSqlQuery& DbManager::query()
{
    return m_query;
}

void DbManager::setQuery(const QSqlQuery &query)
{
    m_query = query;
}

QString &DbManager::error()
{
    return m_error;
}

void DbManager::setError(const QString &error)
{
    m_error = error;
}

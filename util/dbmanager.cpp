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

bool DbManager::queryExec()
{
    if(!m_query.exec())
    {
        if(!m_db.open())
        {
            qDebug() << "reopen failed" << m_db.lastError() << m_query.lastQuery();
            return false;
        }
        this->setQuery(QSqlQuery(m_query.lastQuery(), m_db));
        if(!m_query.exec())
        {
            qDebug() << m_error << m_query.lastError() << m_query.lastQuery();
            return false;
        }
    }
    return true;
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

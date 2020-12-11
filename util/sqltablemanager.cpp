#include "sqltablemanager.h"

SqlTableManager::SqlTableManager(const QString &tableName, const QString &error)
{
    m_db = Dlt698::ConnectionPool::getInstance().openConnection();
    m_query = QSqlQuery(m_db);

//    m_table = new QSqlTableModel(this, m_db);
//    m_table->setTable(tableName);
}

SqlTableManager::~SqlTableManager()
{
    Dlt698::ConnectionPool::getInstance().closeConnection(m_db);
}

QString SqlTableManager::error() const
{
    return m_error;
}

void SqlTableManager::setError(const QString &error)
{
    m_error = error;
}

QSqlQuery SqlTableManager::query() const
{
    return m_query;
}

void SqlTableManager::setQuery(const QSqlQuery &query)
{
    m_query = query;
}

QSqlDatabase SqlTableManager::db() const
{
    return m_db;
}

QSqlTableModel *SqlTableManager::table() const
{
    return m_table;
}

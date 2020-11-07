#include "connectionpool.h"
#include <QSqlError>

using namespace Dlt698;
using namespace std;

ConnectionPool::ConnectionPool()
{
    hostName     = "127.0.0.1";
    databaseName = "test";
    username     = "root";
    password     = "arm";
    databaseType = "QMYSQL";
    port = 3306;

    stop = false;
}

int ConnectionPool::getPort() const
{
    return port;
}

void ConnectionPool::setPort(int value)
{
    port = value;
}

QString ConnectionPool::getPassword() const
{
    return password;
}

void ConnectionPool::setPassword(const QString &value)
{
    password = value;
}

QString ConnectionPool::getUsername() const
{
    return username;
}

void ConnectionPool::setUsername(const QString &value)
{
    username = value;
}

QString ConnectionPool::getDatabaseName() const
{
    return databaseName;
}

void ConnectionPool::setDatabaseName(const QString &value)
{
    databaseName = value;
}

QString ConnectionPool::getHostName() const
{
    return hostName;
}

void ConnectionPool::setHostName(const QString &value)
{
    hostName = value;
}

void ConnectionPool::createConnection(size_t size)
{
    for(size_t i = 0;i < size;i ++)
    {
        QString connectionName = QString("Connection-%1").arg(i);
        QSqlDatabase db = QSqlDatabase::addDatabase(databaseType, connectionName);
        db.setHostName(this->hostName);
        db.setDatabaseName(this->databaseName);
        db.setUserName(this->username);
        db.setPassword(this->password);
        db.setPort(this->port);

        if(!db.open())
        {
            qDebug() << "open database error:" << db.lastError().text();
        }
        else
        {
            this->connectionNames.enqueue(connectionName);
        }
    }
}

ConnectionPool &ConnectionPool::getInstance()
{
    static ConnectionPool pool;
    return pool;
}

QSqlDatabase ConnectionPool::openConnection()
{
    QSqlDatabase db;
    {
        unique_lock<mutex> lock(this->queue_mutex);
        this->condition.wait(lock,
                             [this]{
            return this->stop || !this->connectionNames.empty();
        });
        if(this->connectionNames.empty())
            return QSqlDatabase();

        db = QSqlDatabase::database(this->connectionNames.front());
        this->connectionNames.pop_front();
    }
    return db;
}

void ConnectionPool::closeConnection(QSqlDatabase connection)
{
    {
        unique_lock<mutex> lock(queue_mutex);

        if(stop)
            throw runtime_error("enqueue on stopped ConnectionPool");

        this->connectionNames.enqueue(connection.connectionName());
    }
    condition.notify_one();
}

ConnectionPool::~ConnectionPool()
{
    {
        unique_lock<mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();

//    for(auto &name : connectionNames)
//    {
//        qDebug() << name;
//        QSqlDatabase::removeDatabase(name);
//    }
}

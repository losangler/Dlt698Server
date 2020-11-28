#include "connectionpool.h"
#include "config/databasexml.h"

#include <QSqlError>
#include <QDebug>
#include <QHash>

using namespace Dlt698;
using namespace std;

ConnectionPool::ConnectionPool()
{
    QHash<QString, QString> dataBase = DataBaseXml::instance().getTable("database");

    if((hostName     = dataBase.value("hostName")).isEmpty())
        hostName = "127.0.0.1";
    if((databaseName = dataBase.value("databaseName")).isEmpty())
        databaseName = "test";
    if((username = dataBase.value("username")).isEmpty())
        username     = "root";
    if((password = dataBase.value("password")).isEmpty())
        password     = "arm";
    if((databaseType = dataBase.value("databaseType")).isEmpty())
        databaseType = "QMYSQL";
    if((port = dataBase.value("port").toInt()) == 0)
        port = 3306;
    if((connectSize = dataBase.value("connectSize").toUInt()) == 0)
        connectSize = 10;

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
    if(size != connectSize)
        size = connectSize;

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

void ConnectionPool::init()
{
    QSqlDatabase db = this->openConnection();
    QSqlQuery query(db);
    if(!db.isOpen())
    {
        qDebug() << "open faled";
    }

    QHash<QString, QString> dataBase = DataBaseXml::instance().getTable("tables");
    for(auto k : dataBase)
    {
        foreach(QString sq, k.split(";"))
        {
            if(!query.exec(sq))
            {
                qDebug() << db.lastError() << sq;
            }
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

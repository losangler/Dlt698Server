#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <QtSql>
#include <QQueue>
#include <QString>
#include <mutex>
#include <condition_variable>

namespace Dlt698 {

class ConnectionPool
{
public:
    static ConnectionPool& getInstance();

    QSqlDatabase openConnection();

    void closeConnection(QSqlDatabase connection);

    void createConnection(size_t size = 10);

    ~ConnectionPool();

    QString getHostName() const;
    void setHostName(const QString &value);

    QString getDatabaseName() const;
    void setDatabaseName(const QString &value);

    QString getUsername() const;
    void setUsername(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    int getPort() const;
    void setPort(int value);

private:
    ConnectionPool();

private:
    QQueue<QString> connectionNames;

    QString hostName;
    QString databaseName;
    QString username;
    QString password;
    QString databaseType;
    int port;

    bool stop;
    std::mutex queue_mutex;
    std::condition_variable condition;
};

}

#endif // CONNECTIONPOOL_H

#ifndef SERVERMODEL_H
#define SERVERMODEL_H

#include "model.h"

class ServerModel : public Model
{
    Q_OBJECT

    Q_PROPERTY(QString ip READ ip WRITE setIp NOTIFY ipChanged)

    Q_PROPERTY(QString port READ port WRITE setPort NOTIFY portChanged)

    Q_PROPERTY(QString timeOut READ timeOut WRITE setTimeOut NOTIFY timeOutChanged)

    Q_PROPERTY(QString connectMax READ connectMax WRITE setConnectMax NOTIFY connectMaxChanged)
public:
    explicit ServerModel(QObject *parent = 0);

    explicit ServerModel(QString port, QString timeOut = "3000", QString connectMax = "10", QString ip = "127.0.0.1", QObject *parent = nullptr);

    QString ip() const;
    void setIp(const QString &ip);

    QString port() const;
    void setPort(const QString &port);

    QString timeOut() const;
    void setTimeOut(const QString &timeOut);

    QString connectMax() const;
    void setConnectMax(const QString &connectMax);

signals:
    void ipChanged();

    void portChanged();

    void timeOutChanged();

    void connectMaxChanged();

public slots:

private:
    QString m_ip;
    QString m_port;
    QString m_timeOut;
    QString m_connectMax;
};

#endif // SERVERMODEL_H

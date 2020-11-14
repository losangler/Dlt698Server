#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit Model(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
};

#endif

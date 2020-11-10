#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QObject>

class DataObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
public:
    explicit DataObject(QObject *parent = 0);
    DataObject(const QString &name, const QString &color, QObject *parent = 0);

    QString name() const;
    void setName(const QString &name);

    QString color() const;
    void setColor(const QString &color);
signals:
    void nameChanged();
    void colorChanged();

public slots:

private:
    QString m_name;
    QString m_color;
};

#endif // DATAOBJECT_H

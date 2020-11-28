#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QSet>

class Model : public QObject
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

    void setNotNull(const QString& property);
    void setNull(const QString& property);
    bool isNull(const QString& property);

private:
    QSet<QString> m_property;
};

#endif

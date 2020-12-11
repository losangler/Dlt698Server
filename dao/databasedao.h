#ifndef DATABASEDAO_H
#define DATABASEDAO_H

#include <QObject>
#include <QMetaProperty>
#include <QHash>
#include <QDebug>
#include <QList>
#include <QSqlDatabase>

#include "config/configelement.h"
#include "config/databasexml.h"
#include "util/dbmanager.h"

template<typename T>
class DataBaseDao : public QObject
{
public:
    explicit DataBaseDao(const QString& tableName,QObject* parent = nullptr);

    QList<T *> list();

    QList<T *> selectBy(const QVariant &value, const char* key = "id");

    bool save(T& model);

    bool update(T& model, const char* key = "id");

    bool deleteBy(const QVariant &value, const char* key = "id");

    QList<T *> dataToObject(QSqlQuery &query);

private:
    QString m_tableName;

    QHash<QString, QString> m_table;
};

using namespace Dlt698;

template<typename T>
DataBaseDao<T>::DataBaseDao(const QString &tableName, QObject *parent)
    : QObject(parent), m_tableName(tableName)
{
    m_table = DataBaseXml::instance().getTable(tableName);
}

template<typename T>
QList<T*> DataBaseDao<T>::list()
{
    return selectBy(1, "1");
}

template<typename T>
QList<T *> DataBaseDao<T>::selectBy(const QVariant &value, const char *key)
{
    QString sql = QString("SELECT * FROM %1 WHERE %2 = ?").arg(m_tableName, key);
    DbManager manager("select error");
    manager.query().prepare(sql);
    manager.query().addBindValue(value);
    if(manager.queryExec() == true)
    {
        return this->dataToObject(manager.query());
    }
    return QList<T*>();
}

template<typename T>
bool DataBaseDao<T>::save(T &model)
{
    QString keys = QString("INSERT INTO %1 (").arg(m_tableName);
    QString values = QString("VALUES (");
    const QMetaObject* metaObj = model.metaObject();
    int propertyCnt = metaObj->propertyCount();
    for(int i = 1;i < propertyCnt; ++ i)
    {
        const char* property = metaObj->property(i).name();
        if(model.isNull(property))
            continue;

        keys += m_table.value(property);
        values += "?";
        if(i == propertyCnt - 1)
        {
            keys += ")";
            values += ")";
        }
        else
        {
            keys += ",";
            values += ",";
        }

    }

    DbManager manager("insert error");
    manager.query().prepare(keys + values);
    for(int i = 1;i < propertyCnt; ++ i)
    {
        const char* property = metaObj->property(i).name();
        if(model.isNull(property))
            continue;

        manager.query().addBindValue(model.property(property));
    }

    return manager.queryExec();
}

template<typename T>
bool DataBaseDao<T>::update(T &model, const char *key)
{
    QString sqlTail = QString("WHERE %1 = ?").arg(key);
    QString sql = "UPDATE " + m_tableName + " SET ";
    const QMetaObject *metaObj = model.metaObject();
    int propertyCnt = metaObj->propertyCount();
    for(int i = 1;i < propertyCnt; ++i)
    {
        const char* property = metaObj->property(i).name();
        if(model.isNull(property) || strcmp(property, key) == 0)
            continue;
        sql += m_table.value(property) + "=?";
        if(i != propertyCnt - 1)
            sql += ",";
        else sql += " ";
    }

    DbManager manager("update error");
    manager.query().prepare(sql + sqlTail);
    for(int i = 1;i < propertyCnt; ++ i)
    {
        const char* property = metaObj->property(i).name();
        if(model.isNull(property) || strcmp(property, key) == 0)
            continue;
        manager.query().addBindValue(model.property(property));
    }
    manager.query().addBindValue(model.property(key));
    return manager.queryExec();
}

template<typename T>
bool DataBaseDao<T>::deleteBy(const QVariant &value, const char *key)
{
    QString sql = QString("DELETE FROM %1 where %2 = ?").arg(m_tableName, key);
    DbManager manager("delete error");
    manager.query().prepare(sql);
    manager.query().addBindValue(value);
    return manager.queryExec();
}

template<typename T>
QList<T*> DataBaseDao<T>::dataToObject(QSqlQuery &query)
{
    QList<T*> res;
    QSqlRecord rec = query.record();
    const QMetaObject* metaObj = T().metaObject();
    int propertyCnt = metaObj->propertyCount();

    while(query.next())
    {
        T* model = new T();
        for(int i = 1;i < propertyCnt;i ++)
        {
            const char* property = metaObj->property(i).name();
            if(!rec.contains(m_table.value(property)))
                continue;
            model->setProperty(property, query.value(rec.indexOf(m_table.value(property))));
        }
        res.push_back(model);
    }
    return res;
}

#endif // DATABASEDAO_H

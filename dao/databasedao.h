#ifndef DATABASEDAO_H
#define DATABASEDAO_H

#include <QObject>
#include <QMetaProperty>
#include <QVector>
#include <QDebug>
#include <QList>

#include "config/configelement.h"
#include "config/databasexml.h"

template<typename T>
class DataBaseDao : public QObject
{
public:
    explicit DataBaseDao(const QString& fileName, const QString& tableName,QObject* parent = nullptr);

    QList<T> list();

private:
    QString m_table;
    QVector<QPair<QString, QString> > m_map;
};

template<typename T>
DataBaseDao<T>::DataBaseDao(const QString &fileName, const QString &tableName, QObject *parent)
    : QObject(parent), m_table(tableName)
{
    DataBaseXml xml(fileName);
    if(!xml.OpenXML())
        return;

    ConfigElement elem = xml.getRoot().findChild(tableName);
    QDomNode node = elem.getNode().firstChild();
    while (!node.isNull()) {
        if(node.isElement())
        {
            QDomElement domElement = node.toElement();
            m_map.push_back(QPair<QString, QString>(domElement.tagName(), domElement.text()));
        }
        node = node.nextSibling();
    }
}

template<typename T>
QList<T> DataBaseDao<T>::list()
{

}


#endif // DATABASEDAO_H

#ifndef DATABASEXML_H
#define DATABASEXML_H

#include <QObject>
#include <QFile>
#include <QMap>
#include <QDomDocument>

#include "configelement.h"

class DataBaseXml
{
public:
    explicit DataBaseXml(const QString &fileName = "config.xml");

    bool OpenXML();

    void Save();

    ConfigElement getRoot() const;

    QString getFileName() const;
    void setFileName(const QString &fileName);

private:
    QString m_fileName;
    QDomDocument doc;
    ConfigElement root;
};

#endif // DATABASEXML_H

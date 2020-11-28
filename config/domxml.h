#ifndef DOMXML_H
#define DOMXML_H

#include <QObject>
#include <QFile>
#include <QDomDocument>

#include "configelement.h"

class DomXml
{
public:
    explicit DomXml(const QString &fileName = "config.xml");

    bool OpenXML();
    void Save();
    void CloseXml();

    ConfigElement getRoot() const;
    virtual const char* getConfigEnv();

    QString getFileName() const;
    void setFileName(const QString &fileName);

private:
    QString m_fileName;
    QDomDocument doc;
    ConfigElement root;
};

#endif // DOMXML_H

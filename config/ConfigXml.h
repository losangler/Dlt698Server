#ifndef CONFIGXML_H
#define CONFIGXML_H

#include <QObject>
#include <QFile>
#include <QMap>
#include <QDomDocument>

#include "configelement.h"

class ConfigXml
{
public:
    bool OpenXML();

    void Save();

    static ConfigXml& instance();

    ConfigElement getRoot() const;

private:
    explicit ConfigXml();

    QDomDocument doc;
    ConfigElement root;

    QString fileName = "../Dlt698View/config/config.xml";
    const char* configXmlEnv = "CONFIG_XML_ENV";
};

#endif

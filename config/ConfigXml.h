#ifndef CONFIGXML_H
#define CONFIGXML_H

#include <QObject>
#include <QFile>
#include <QMap>
#include <QDomDocument>

#include "configelement.h"
#include "databasexml.h"

class ConfigXml : public DataBaseXml
{
public:
    static ConfigXml& instance();

private:
    explicit ConfigXml();

    const char* configXmlEnv = "CONFIG_XML_ENV";
};

#endif

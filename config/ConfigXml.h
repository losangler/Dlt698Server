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
    const char* fileName = "../config/config.xml";
};

#endif

#include "config/ConfigXml.h"
#include <QDebug>

ConfigXml::ConfigXml()
    : DataBaseXml("../Dlt698View/config/config.xml")
{
    QString path(::qgetenv(this->configXmlEnv));
    if(!path.isEmpty())
        this->setFileName(path);

    this->OpenXML();
}

ConfigXml &ConfigXml::instance()
{
    static ConfigXml instacne;
    return instacne;
}

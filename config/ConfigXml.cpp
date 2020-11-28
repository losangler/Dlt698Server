#include "config/ConfigXml.h"
#include <QDebug>

ConfigXml::ConfigXml()
    : DomXml("../Dlt698View/config/config.xml")
{
    this->OpenXML();
}

const char *ConfigXml::getConfigEnv()
{
    return "CONFIG_XML_ENV";
}

ConfigXml &ConfigXml::instance()
{
    static ConfigXml instacne;
    return instacne;
}

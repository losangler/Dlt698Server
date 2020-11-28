#ifndef CONFIGXML_H
#define CONFIGXML_H

#include "configelement.h"
#include "domxml.h"

class ConfigXml : public DomXml
{
public:
    static ConfigXml& instance();

private:
    explicit ConfigXml();

    // DataBaseXml interface
public:
    virtual const char* getConfigEnv() override;
};

#endif

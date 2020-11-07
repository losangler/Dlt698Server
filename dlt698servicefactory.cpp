#include "dlt698servicefactory.h"

Dlt698Service *Dlt698ServiceFactory::getService(WORD type)
{
    return this->services[type];
}

void Dlt698ServiceFactory::setService(WORD type, Dlt698Service *service)
{
    this->services[type] = service;
}

Dlt698ServiceFactory *Dlt698ServiceFactory::instance()
{
    static Dlt698ServiceFactory factory;
    return &factory;
}

Dlt698ServiceFactory::Dlt698ServiceFactory()
{

}

Dlt698ServiceFactory::~Dlt698ServiceFactory()
{
    for(auto &k : this->services)
    {
        delete k.second;
    }
}


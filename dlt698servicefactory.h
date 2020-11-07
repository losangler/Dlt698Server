#ifndef DLT698SERVICEFACTORY_H
#define DLT698SERVICEFACTORY_H

#include <unordered_map>
#include "dlt698service.h"

class Dlt698ServiceFactory
{
public:
    static Dlt698ServiceFactory *instance();

    Dlt698Service* getService(WORD type);
    void setService(WORD type, Dlt698Service *service);

private:
    Dlt698ServiceFactory();
    virtual ~Dlt698ServiceFactory();

    unordered_map<WORD, Dlt698Service* > services;
};

#endif // DLT698SERVICEFACTORY_H

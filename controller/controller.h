#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

class Controller
{
public:
    virtual void qmlRegister();

    Controller(std::string qmlName, int versionMajor = 1, int versionMinor = 1, std::string uri = "MyInterface");
protected:
    std::string m_uri;
    int m_versionMajor;
    int m_versionMinor;
    std::string m_qmlName;

};

#endif

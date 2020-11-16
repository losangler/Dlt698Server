#include "controller/controller.h"


void Controller::qmlRegister()
{

}

Controller::Controller(std::__cxx11::string qmlName, int versionMajor, int versionMinor, std::__cxx11::string uri)
    : m_uri(uri), m_qmlName(qmlName), m_versionMajor(versionMajor), m_versionMinor(versionMinor)
{

}

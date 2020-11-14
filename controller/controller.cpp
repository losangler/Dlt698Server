#include "controller/controller.h"

Controller::Controller(QObject *parent)
    : QObject(parent)
{

}

Model *Controller::getModel() const
{
    Model* m = new Model();
    m->setUserName("Controller");
    return m;
}

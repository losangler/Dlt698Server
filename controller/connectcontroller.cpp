#include "connectcontroller.h"
#include "config/ConfigXml.h"

void ConnectController::updateModel(const QString &name) const
{
    this->m_model->setUserName(name);
}

Model *ConnectController::model()
{
    if(m_model == nullptr)
    {
        m_model = new Model(this);
        ConfigElement elem = ConfigXml::instance().getRoot().findChild(c_connect, "port");
        if(!elem.getIsNull())
        {
            m_model->setUserName(elem.getNode().text());
        }
    }
    return m_model;
}

QObject *ConnectController::singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    ConnectController *example = new ConnectController();

    return example;
}

ConnectController::ConnectController(QObject *parent)
    : QObject(parent)
{

}

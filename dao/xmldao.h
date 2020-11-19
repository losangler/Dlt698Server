#ifndef XMLDAO_H
#define XMLDAO_H

#include <QObject>
#include <QMetaProperty>
#include "config/configelement.h"
#include "config/ConfigXml.h"

template<typename T>
class XmlDao : public QObject
{
public:
    explicit XmlDao(QObject* parent = nullptr);

    void saveModel(T& model);

    T *getModel();

protected:
    ConfigElement m_elem;
};

template<typename T>
XmlDao<T>::XmlDao(QObject *parent)
    : QObject(parent)
{

}

template<typename T>
void XmlDao<T>::saveModel(T &model)
{
    const QMetaObject* metaObj = model.metaObject();
    int propertyCnt = metaObj->propertyCount();
    for(int i = 0;i < propertyCnt; ++ i)
    {
        QMetaProperty oneProperty = metaObj->property(i);
        m_elem.findChild(oneProperty.name()).setText(model.property(oneProperty.name()).toString());
    }
}

template<typename T>
T* XmlDao<T>::getModel()
{
    T *model = new T();
    const QMetaObject* metaObj = model->metaObject();
    int propertyCnt = metaObj->propertyCount();
    for(int i = 0;i < propertyCnt; ++ i)
    {
        QMetaProperty oneProperty = metaObj->property(i);
        model->setProperty(oneProperty.name(), m_elem.findChild(oneProperty.name()).getText());
    }
    return model;
}

#endif

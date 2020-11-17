#ifndef CONFIGELEMENT_H
#define CONFIGELEMENT_H

#include <QDomElement>

class ConfigElement
{
public:
    ConfigElement(const QDomElement &element);
    ConfigElement();

    ConfigElement findChild(QString key);
    template<typename ...Pack>
    ConfigElement findChild(QString key, Pack... pack);

    QDomElement getNode() const;
    void setNode(const QDomElement &value);

    bool IsNull() const;

    void setText(QString text);
    QString getText() const;

private:
    QDomElement node;
    bool isNull;
};

template<typename ...Pack>
ConfigElement ConfigElement::findChild(QString key, Pack... pack)
{
    return this->findChild(key).findChild(pack...);
}

#endif // CONFIGELEMENT_H

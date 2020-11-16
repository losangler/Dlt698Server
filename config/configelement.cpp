#include "configelement.h"

ConfigElement::ConfigElement(const QDomElement &element)
    : node(element), isNull(false)
{

}

ConfigElement::ConfigElement()
    : isNull(true)
{

}

ConfigElement ConfigElement::findChild(QString key)
{
    if(this->isNull)
        return *(new ConfigElement());

    QDomNode node = this->node.firstChild();
    while (!node.isNull()) {
        if(node.isElement())
        {
            QDomElement domElement = node.toElement();
            if(domElement.tagName() == key)
            {
                return *(new ConfigElement(domElement));
            }
        }
        node = node.nextSibling();
    }

    return *(new ConfigElement());
}


QDomElement ConfigElement::getNode() const
{
    return node;
}

void ConfigElement::setNode(const QDomElement &value)
{
    this->isNull = false;
    node = value;
}

bool ConfigElement::getIsNull() const
{
    return isNull;
}

void ConfigElement::setText(QString text)
{
    if(this->isNull || this->node.firstChild().isNull())
        return;
    this->node.firstChild().setNodeValue(text);
}

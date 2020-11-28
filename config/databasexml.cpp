#include "databasexml.h"
#include "configelement.h"

DataBaseXml &DataBaseXml::instance()
{
    static DataBaseXml instance;
    return instance;
}

void DataBaseXml::init()
{
    QDomNode node = this->getRoot().getNode().firstChild();
    while (!node.isNull())
    {
        if(node.isElement())
        {
            QDomElement elem = node.toElement();
            QDomNode n_node = elem.firstChild();
            while(!n_node.isNull())
            {
                if(n_node.isElement())
                {
                    QDomElement n_elem = n_node.toElement();
                    m_tables[elem.tagName()][n_elem.tagName()] = n_elem.text();
                }
                n_node = n_node.nextSibling();
            }

        }
        node = node.nextSibling();
    }
}

DataBaseXml::DataBaseXml()
    : DomXml("../Dlt698View/config/DBconfig.xml")
{
    this->OpenXML();
    this->init();
    this->CloseXml();
}

const char *DataBaseXml::getConfigEnv()
{
    return "DATA_BASE_ENV";
}

QHash<QString, QHash<QString, QString> > DataBaseXml::getTables() const
{
    return m_tables;
}

QHash<QString, QString> DataBaseXml::getTable(const QString &tableName) const
{
    return m_tables.value(tableName);
}


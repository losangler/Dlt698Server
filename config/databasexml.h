#ifndef DATABASEXML_H
#define DATABASEXML_H

#include <QHash>

#include "configelement.h"
#include "domxml.h"

class DataBaseXml : public DomXml
{
public:
    static DataBaseXml& instance();

    void init();

    QHash<QString, QHash<QString, QString> > getTables() const;

    QHash<QString, QString> getTable(const QString& tableName) const;
private:
    explicit DataBaseXml();

    // DomXml interface
public:
    virtual const char *getConfigEnv() override;

private:
    QHash<QString, QHash<QString, QString> > m_tables;
};

#endif // DATABASEXML_H

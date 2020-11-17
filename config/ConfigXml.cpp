#include "config/ConfigXml.h"
#include <QDebug>

ConfigXml::ConfigXml()
{
    QString path(::qgetenv(this->configXmlEnv));
    if(!path.isEmpty())
        this->fileName = path;

    this->OpenXML();
}

ConfigElement ConfigXml::getRoot() const
{
    return root;
}

bool ConfigXml::OpenXML()
{
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        qDebug() << fileName << "open failed";
        return false;
    }

    QString error;
    int row = 0, column = 0;
    if(!doc.setContent(&file, false, &error, &row, &column))
    {
        qDebug() << "parse file failed at line row and column" + QString::number(row, 10) + QString(",") + QString::number(column, 10);
        file.close();
        return false;
    }
    root.setNode(doc.documentElement());
    file.close();

    return true;
}

void ConfigXml::Save()
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << fileName << "open failed";
        return;
    }

    QTextStream out(&file);
    doc.save(out, 4);
    file.close();
}

ConfigXml &ConfigXml::instance()
{
    static ConfigXml instacne;
    return instacne;
}

#include "domxml.h"
#include <QDebug>

DomXml::DomXml(const QString &fileName)
    : m_fileName(fileName)
{
    QString path(::qgetenv(this->getConfigEnv()));
    if(!path.isEmpty())
        this->m_fileName = path;
}

bool DomXml::OpenXML()
{
    QFile file(m_fileName);

    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        qDebug() << m_fileName << "open failed";
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

void DomXml::Save()
{
    QFile file(m_fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << m_fileName << "open failed";
        return;
    }

    QTextStream out(&file);
    doc.save(out, 4);
    file.close();
}

void DomXml::CloseXml()
{
    this->doc.clear();
}

ConfigElement DomXml::getRoot() const
{
    return root;
}

const char *DomXml::getConfigEnv()
{
    return "DB_CONFIG_ENV";
}

QString DomXml::getFileName() const
{
    return m_fileName;
}

void DomXml::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

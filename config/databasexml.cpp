#include "databasexml.h"
#include <QDebug>

DataBaseXml::DataBaseXml(const QString &fileName)
    : m_fileName(fileName)
{

}

bool DataBaseXml::OpenXML()
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

void DataBaseXml::Save()
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

ConfigElement DataBaseXml::getRoot() const
{
    return root;
}

QString DataBaseXml::getFileName() const
{
    return m_fileName;
}

void DataBaseXml::setFileName(const QString &fileName)
{
    m_fileName = fileName;
}

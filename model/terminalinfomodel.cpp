#include "terminalinfomodel.h"

TerminalInfoModel::TerminalInfoModel(QObject *parent)
    : Model(parent)
{

}

int TerminalInfoModel::id() const
{
    return m_id;
}

void TerminalInfoModel::setId(int id)
{
    this->setNotNull("id");
    if(m_id == id)
        return;
    m_id = id;
    emit idChanged();
}

int TerminalInfoModel::terminalId() const
{
    return m_terminalId;
}

void TerminalInfoModel::setTerminalId(int terminalId)
{
    this->setNotNull("terminalId");
    if(m_terminalId == terminalId)
        return;
    m_terminalId = terminalId;
    emit terminalIdChanged();
}

int TerminalInfoModel::current() const
{
    return m_current;
}

void TerminalInfoModel::setCurrent(int current)
{
    this->setNotNull("current");
    if(m_current == current)
        return;
    m_current = current;
    emit currentChanged();
}

double TerminalInfoModel::longitude() const
{
    return m_longitude;
}

void TerminalInfoModel::setLongitude(double longitude)
{
    this->setNotNull("longitude");
    if(m_longitude == longitude)
         return;
    m_longitude = longitude;
    emit longitudeChanged();
}

double TerminalInfoModel::latitude() const
{
    return m_latitude;
}

void TerminalInfoModel::setLatitude(double latitude)
{
    this->setNotNull("latitude");
    if(m_latitude == latitude)
        return;
    m_latitude = latitude;
    emit latitudeChanged();
}

unsigned int TerminalInfoModel::height() const
{
    return m_height;
}

void TerminalInfoModel::setHeight(unsigned int height)
{
    this->setNotNull("height");
    if(m_height == height)
         return;
    m_height = height;
    emit heightChanged();
}

QDateTime TerminalInfoModel::dateTime() const
{
    return m_dateTime;
}

void TerminalInfoModel::setDateTime(const QDateTime &dateTime)
{
    this->setNotNull("dateTime");
    if(m_dateTime == dateTime)
        return;
    m_dateTime = dateTime;
    emit dateTimeChanged();
}

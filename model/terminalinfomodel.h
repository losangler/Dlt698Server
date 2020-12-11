#ifndef TERMINALINFOMODEL_H
#define TERMINALINFOMODEL_H

#include <QDateTime>
#include "model.h"

class TerminalInfoModel : public Model
{
Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)

    Q_PROPERTY(int terminalId READ terminalId WRITE setTerminalId NOTIFY terminalIdChanged)

    Q_PROPERTY(int current READ current WRITE setCurrent NOTIFY currentChanged)

    Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)

    Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)

    Q_PROPERTY(unsigned int height READ height WRITE setHeight NOTIFY heightChanged)

    Q_PROPERTY(QDateTime dateTime READ dateTime WRITE setDateTime NOTIFY dateTimeChanged)

public:
    explicit TerminalInfoModel(QObject* parent = nullptr);

    int id() const;
    void setId(int id);

    int terminalId() const;
    void setTerminalId(int terminalId);

    int current() const;
    void setCurrent(int current);

    double longitude() const;
    void setLongitude(double longitude);

    double latitude() const;
    void setLatitude(double latitude);

    unsigned int height() const;
    void setHeight(unsigned int height);

    QDateTime dateTime() const;
    void setDateTime(const QDateTime &dateTime);

signals:
    void idChanged();

    void terminalIdChanged();

    void currentChanged();

    void longitudeChanged();

    void latitudeChanged();

    void heightChanged();

    void dateTimeChanged();

private:
    int m_id;
    int m_terminalId;
    int m_current;
    double m_longitude;
    double m_latitude;
    unsigned int m_height;
    QDateTime m_dateTime;
};

#endif // TERMINALINFOMODEL_H

#ifndef TERMINALMODEL_H
#define TERMINALMODEL_H

#include "model.h"
#include <QString>

class TerminalModel : public Model
{
    Q_OBJECT

    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)

    Q_PROPERTY(QString addr READ addr WRITE setAddr NOTIFY addrChanged)

    Q_PROPERTY(int status READ status WRITE setStatus NOTIFY statusChanged)
public:
    explicit TerminalModel(QObject* parent = nullptr);

    int id() const;
    void setId(int id);

    QString addr() const;
    void setAddr(const QString &addr);

    int status() const;
    void setStatus(int status);

signals:
    void idChanged();

    void addrChanged();

    void statusChanged();

private:
    int m_id;
    QString m_addr;
    int m_status;
};

#endif // TERMINALMODEL_H

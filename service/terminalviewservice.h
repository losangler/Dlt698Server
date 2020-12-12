#ifndef TERMINALVIEWSERVICE_H
#define TERMINALVIEWSERVICE_H

#include "QSqlQueryModel"
#include "service.h"

class TerminalViewService : public Service
{
public:
    explicit TerminalViewService(QObject *parent = nullptr);


    int getPages(int limit = 10);
    QVariantMap getDateTimesAndCurrent();

    QSqlQueryModel *terminalView(int offset = 0, int limit = 10);
    void setTerminalView(QSqlQueryModel *terminalView);

private:
    QSqlQueryModel *m_terminalView = nullptr;
};

#endif // TERMINALVIEWSERVICE_H

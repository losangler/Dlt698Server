#ifndef CONNECTCONTROLLER_H
#define CONNECTCONTROLLER_H

#include <QQmlEngine>
#include "service/serverservice.h"
#include "service/terminalservice.h"
#include "service/terminalinfoservice.h"
#include "service/terminalviewservice.h"
#include "controller.h"

class ConnectController : public Controller
{
    Q_OBJECT

public:
    Q_INVOKABLE ServerModel *serverModel();

    Q_INVOKABLE void serverUpdate();

    Q_INVOKABLE void saveConfig();

    Q_INVOKABLE void getAllTermianl();

    Q_INVOKABLE QSqlQueryModel *terminalViewModel(int offset = 0, int limit = 10);

    Q_INVOKABLE int getTerminalViewPages(int limit = 10);

    Q_INVOKABLE QVariantMap getTimeAndCurrent();

    static QObject *singletontype_provider(QQmlEngine *engine, QJSEngine *scriptEngine);

private:
    explicit ConnectController(QObject *parent = nullptr);

    ServerService *m_server;

    TerminalService *m_tService;

    TerminalInfoService *m_tiService;

    TerminalViewService *m_terminalViewService;
};

#endif // CONNECTCONTROLLER_H

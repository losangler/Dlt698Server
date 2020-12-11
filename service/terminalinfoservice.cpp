#include "terminalinfoservice.h"
#include <QDebug>
#include <QList>

TerminalInfoService::TerminalInfoService(QObject *parent)
    : Service(parent)
{

}

void TerminalInfoService::test()
{
    QList<TerminalInfoModel*> list = m_dao.selectBy(1);

    TerminalInfoModel* model = list.at(0);
    qDebug() << model->id() << model->terminalId() << model->current() << model->longitude() << model->latitude() << model->dateTime().toString("yyyy-MM-dd hh:mm:ss");
}

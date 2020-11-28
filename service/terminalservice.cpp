#include "terminalservice.h"
#include <QVariant>
#include <QDebug>

TerminalService::TerminalService(QObject *parent)
    : Service(parent)
{

}

void TerminalService::test()
{
//    QList<TerminalModel*> list = m_dao.list();
//    for(auto k : list)
//    {
//        qDebug() << k->id() << k->addr() << k->status();
//    }

    TerminalModel model;
    model.setAddr("66 66");
    model.setStatus(1);
    //model.setId(4);
    m_dao.save(model);


//    int x = 0;
//    QString string();
//    QVariant number(string);
//    if(!number.isNull())
//        qDebug() << x;
//    else qDebug() << "null";

//    m_dao.deleteBy("66 66", "addr");
}


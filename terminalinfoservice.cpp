#include "terminalinfoservice.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

using namespace Dlt698;

TerminalInfoService::TerminalInfoService()
{

}

bool TerminalInfoService::save(TerminalInfoEntity &entity)
{
    QSqlQuery query(this->db);
    query.prepare("INSERT INTO terminalInfo (terminal_id, current, longitude, latitude, height, date_time)"
                  "VALUES (:terminalId, :current, :longitude, :latitude, :height, :dateTime)");
    query.bindValue(":terminalId", entity.getTerminalId());
    query.bindValue(":current", entity.getCurrent());
    query.bindValue(":longitude", entity.getLongitude());
    query.bindValue(":latitude", entity.getLatitude());
    query.bindValue(":height", entity.getHeight());
    query.bindValue(":dateTime", entity.getDateTime().data());

    if(!query.exec())
    {
        qDebug() << "insert database error:" << this->db.lastError();
        return false;
    }
    return true;
}

bool TerminalInfoService::saveTest(TerminalInfoEntity &entity)
{
    QSqlQuery query(this->db);
    query.prepare("INSERT INTO terminalInfo (terminal_id, current, longitude, latitude, height, date_time)"
//                  "VALUES (1, 100, -23.1, -123.23, 0, '2020-10-31 15:25:')");
                  "VALUES (:terminalId, :current, :longitude, :latitude, :height, :dateTime)");
    query.bindValue(":terminalId", entity.getTerminalId());
    query.bindValue(":current", entity.getCurrent());
    query.bindValue(":longitude", entity.getLongitude());
    query.bindValue(":latitude", entity.getLatitude());
    query.bindValue(":height", entity.getHeight());
    query.bindValue(":dateTime", "2020-10-31 15:33:24");

    if(!query.exec())
    {
        qDebug() << "insert database error:" << this->db.lastError();
        return false;
    }
    return true;
}
